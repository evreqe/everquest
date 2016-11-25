<?php

function convert_item_name_to_wiki_name($text)
{
    $text = str_replace('Song:', 'Spell:', $text); // redirect Songs to Spells

    $text = str_replace('10 Dose ', '', $text); // fix potions

    $text = str_replace(' ', '_', $text);

    return $text;
}

function fix_item_name($text)
{
    //$text = str_replace('`', "'", $text); // tilde fix

    $text = str_replace('&lsquo;', "'", $text); // quote fix

    $text = str_replace('Shirtri', 'Shiritri', $text); // Shiritri typo fix

    return $text;
}

function string_between($s, $l, $r)
{  
    $il = strpos($s, $l, 0) + strlen($l);
    $ir = strpos($s, $r, $il);
    return substr($s, $il, ($ir - $il));
}

include('simple_html_dom.php');

set_time_limit(0); // prevent maximum execution time timeout

echo '<h3>Scrape Vendor List</h3>';

$character_names = Array();

$item_names = Array();

$vendor_list = '{"data":[';

$dump = '';

$file_get_context = stream_context_create(array('http' => array('header' => 'Connection: close')));

$listinvdata = file_get_html('https://shardsofdalaya.com/vendorlist/listinvdata.php', false, $file_get_context);

//echo 'listinvdata: ' . $listinvdata . '<br>';

$pages = Array();

foreach ($listinvdata->find('a') as $listinvdata_link)
{
    if (strpos($listinvdata_link->href, 'listinvdata.php?page=') !== false)
    {
        $page = substr($listinvdata_link->href, strpos($listinvdata_link->href, '?page=') + strlen('?page='));

        array_push($pages, $page);
    }
}

$max_pages = max($pages);

for ($character_pages_counter = 1; $character_pages_counter <= $max_pages; $character_pages_counter++)
{
    $listinvdata = file_get_html('https://shardsofdalaya.com/vendorlist/listinvdata.php?page=' . $character_pages_counter, false, $file_get_context);

    echo 'Page: ' . $character_pages_counter . '<br><br>';

    foreach ($listinvdata->find('a') as $listinvdata_link)
    {
        if (strpos($listinvdata_link->href, 'vendorinv.php?char=') !== false)
        {
            $character_name = substr($listinvdata_link->href, strpos($listinvdata_link->href, '?char=') + strlen('?char='));

            array_push($character_names, $character_name);

            $dump .= $character_name . "\n";

            echo 'Character: ' . $character_name . '<br>';

            $vendorinv = file_get_html('https://shardsofdalaya.com/vendorlist/vendorinv.php?char=' . $character_name, false, $file_get_context);

            $number_of_items_for_sale = string_between($vendorinv->plaintext, $character_name . ' has ', ' items for sale');

            $number_of_items_per_page = 10;

            $max_item_pages = ceil($number_of_items_for_sale / $number_of_items_per_page);

            if ($number_of_items_for_sale == 0)
            {
                continue;
            }

            for ($item_pages_counter = 1; $item_pages_counter <= $max_item_pages; $item_pages_counter++)
            {
                $vendorinv = file_get_html('https://shardsofdalaya.com/vendorlist/vendorinv.php?char=' . $character_name . '&page=' . $item_pages_counter, false, $file_get_context);

                foreach ($vendorinv->find('a') as $vendorinv_link)
                {
                    if (strpos($vendorinv_link->href, 'items.php?id=') !== false)
                    {
                        $item_name = $vendorinv_link->innertext;

                        $item_name = fix_item_name($item_name);

                        array_push($item_names, $item_name);

                        $dump .= '    ' . $item_name . "\n";

                        $item_image = '';
                        $item_tags = '';
                        $item_hp = '';
                        $item_mana = '';
                        $item_ac = '';
                        $item_dmg = '';
                        $item_atkdelay = '';

                        $item_filename = 'items/' . md5($item_name) . '.txt';

                        if (file_exists($item_filename))
                        {
                            $item_stats = parse_ini_file($item_filename);

                            if (array_key_exists('image', $item_stats))
                            {
                                $item_image = $item_stats['image'];
                            }

                            if (array_key_exists('flagboe', $item_stats))
                            {
                                $item_flagboe = $item_stats['flagboe'];

                                if ($item_flagboe == "1")
                                {
                                    $item_tags .= 'BIND ON EQUIP' . ' ';
                                }
                            }

                            if (array_key_exists('flaglore', $item_stats))
                            {
                                $item_flaglore = $item_stats['flaglore'];

                                if ($item_flaglore == "1")
                                {
                                    $item_tags .= 'LORE ITEM' . ' ';
                                }
                            }

                            if (array_key_exists('flagmagic', $item_stats))
                            {
                                $item_flagmagic = $item_stats['flagmagic'];

                                if ($item_flagmagic == "1")
                                {
                                    $item_tags .= 'MAGIC ITEM' . ' ';
                                }
                            }

                            if (array_key_exists('flagaug', $item_stats))
                            {
                                $item_flagaug = $item_stats['flagaug'];

                                if ($item_flagaug == "1")
                                {
                                    $item_tags .= 'AUGMENTATION' . ' ';
                                }
                            }

                            if (array_key_exists('container', $item_stats))
                            {
                                $item_container = $item_stats['container'];

                                if ($item_container == "1")
                                {
                                    $item_tags .= 'Container' . ' ';
                                }
                            }

                            if (array_key_exists('health', $item_stats))
                            {
                                $item_hp = $item_stats['health'];

                                $item_hp = str_replace('+', '', $item_hp);

                                $item_tags .= 'HP' . ' ';
                            }

                            if (array_key_exists('mana', $item_stats))
                            {
                                $item_mana = $item_stats['mana'];

                                $item_mana = str_replace('+', '', $item_mana);

                                $item_tags .= 'MANA' . ' ';
                            }

                            if (array_key_exists('ac', $item_stats))
                            {
                                $item_ac = $item_stats['ac'];

                                $item_tags .= 'AC' . ' ';
                            }

                            if (array_key_exists('dmg', $item_stats))
                            {
                                $item_dmg = $item_stats['dmg'];
                            }

                            if (array_key_exists('atkdelay', $item_stats))
                            {
                                $item_atkdelay = $item_stats['atkdelay'];
                            }

                            if (array_key_exists('str', $item_stats))
                            {
                                $item_tags .= 'STR' . ' ';
                            }

                            if (array_key_exists('sta', $item_stats))
                            {
                                $item_tags .= 'STA' . ' ';
                            }

                            if (array_key_exists('agi', $item_stats))
                            {
                                $item_tags .= 'AGI' . ' ';
                            }

                            if (array_key_exists('dex', $item_stats))
                            {
                                $item_tags .= 'DEX' . ' ';
                            }

                            if (array_key_exists('wis', $item_stats))
                            {
                                $item_tags .= 'WIS' . ' ';
                            }

                            if (array_key_exists('int', $item_stats))
                            {
                                $item_tags .= 'INT' . ' ';
                            }

                            if (array_key_exists('cha', $item_stats))
                            {
                                $item_tags .= 'CHA' . ' ';
                            }

                            if (array_key_exists('svfire', $item_stats))
                            {
                                $item_tags .= 'SV FIRE' . ' ';
                            }

                            if (array_key_exists('svcold', $item_stats))
                            {
                                $item_tags .= 'SV COLD' . ' ';
                            }

                            if (array_key_exists('svmagic', $item_stats))
                            {
                                $item_tags .= 'SV MAGIC' . ' ';
                            }

                            if (array_key_exists('svdisease', $item_stats))
                            {
                                $item_tags .= 'SV DISEASE' . ' ';
                            }

                            if (array_key_exists('svpoison', $item_stats))
                            {
                                $item_tags .= 'SV POISON' . ' ';
                            }

                            if (array_key_exists('aggression', $item_stats))
                            {
                                $item_tags .= 'Aggression' . ' ';
                            }

                            if (array_key_exists('critstrike', $item_stats))
                            {
                                $item_tags .= 'Critical Strike' . ' ';
                            }

                            if (array_key_exists('dmgreduction', $item_stats))
                            {
                                $item_tags .= 'Damage Reduction' . ' ';
                            }

                            if (array_key_exists('flowingthought', $item_stats))
                            {
                                $item_tags .= 'Flowing Thought' . ' ';
                            }

                            if (array_key_exists('mindshield', $item_stats))
                            {
                                $item_tags .= 'Mind Shield' . ' ';
                            }

                            if (array_key_exists('spellward', $item_stats))
                            {
                                $item_tags .= 'Spell Ward' . ' ';
                            }

                            if (array_key_exists('stunresist', $item_stats))
                            {
                                $item_tags .= 'Stun Resist' . ' ';
                            }

                            if (array_key_exists('skill', $item_stats))
                            {
                                $item_tags .= $item_stats['skill'] . ' ';
                            }

                            if (array_key_exists('focuseffect', $item_stats))
                            {
                                $item_tags .= $item_stats['focuseffect'] . ' ';
                            }

                            if (array_key_exists('effect', $item_stats))
                            {
                                $item_tags .= $item_stats['effect'] . ' ';
                            }

                            if (array_key_exists('effectflag', $item_stats))
                            {
                                $item_tags .= $item_stats['effectflag'] . ' ';
                            }

                            if (array_key_exists('tradeskilled', $item_stats))
                            {
                                $item_tags .= $item_stats['tradeskilled'] . ' ';
                            }

                            if (array_key_exists('skillmod', $item_stats))
                            {
                                $item_tags .= $item_stats['skillmod'] . ' ';

                                $item_tags .= 'Skill Mod' . ' ';
                            }

                            if (array_key_exists('insttypemod', $item_stats))
                            {
                                $item_tags .= $item_stats['insttypemod'] . ' ';

                                $item_tags .= 'Instrument Modifier' . ' ';
                            }

                            if (array_key_exists('spdmgtype', $item_stats))
                            {
                                $item_tags .= $item_stats['spdmgtype'] . ' DMG' . ' ';
                            }

                            if (array_key_exists('wtreduc', $item_stats))
                            {
                                $item_tags .= 'Weight Reduction' . ' ';
                            }

                            if (array_key_exists('size', $item_stats))
                            {
                                $item_tags .= $item_stats['size'] . ' ';
                            }

                            if (array_key_exists('reclvl', $item_stats))
                            {
                                $item_tags .= 'Recommended Level' . ' ';
                            }

                            if (array_key_exists('slots', $item_stats))
                            {
                                $item_slots = $item_stats['slots'];

                                $item_slots = str_replace(',', ' ', $item_slots);

                                $item_tags .= $item_slots . ' ';
                            }

                            if (array_key_exists('classes', $item_stats))
                            {
                                $item_classes = $item_stats['classes'];

                                $item_classes = str_replace(',', ' ', $item_classes);

                                $item_tags .= $item_classes . ' ';
                            }

                            if (array_key_exists('races', $item_stats))
                            {
                                $item_races = $item_stats['races'];

                                $item_races = str_replace(',', ' ', $item_races);

                                $item_tags .= $item_races . ' ';
                            }
                        }

                        if ($item_image == '')
                        {
                            if (strpos($item_name, 'Spell:') !== false || strpos($item_name, 'Song:') !== false)
                            {
                                $item_image = '504';
                            }

                            if (strpos($item_name, 'Quiver of') !== false)
                            {
                                $item_image = '725';
                            }

                            if (strpos($item_name, 'Lining of') !== false)
                            {
                                $item_image = '834';
                            }

                            if (strpos($item_name, 'Sealed') !== false)
                            {
                                if (strpos($item_name, 'Map') !== false)
                                {
                                    $item_image = '863';
                                }
                            }

                            if (strpos($item_name, 'Runes of') !== false)
                            {
                                $item_image = '943';
                            }

                            if (strpos($item_name, 'Sigil of') !== false)
                            {
                                $item_image = '967';
                            }

                            if (strpos($item_name, 'Bundle of') !== false)
                            {
                                if (strpos($item_name, 'Arrows') !== false)
                                {
                                    $item_image = '978';
                                }
                            }

                            if (strpos($item_name, 'Tome of') !== false)
                            {
                                $item_image = '1357';
                            }

                            if ($item_image == '')
                            {
                                $last_2 = substr($item_name, -2);
                                $last_3 = substr($item_name, -3);
                                $last_4 = substr($item_name, -4);

                                if ($last_2 == ' I' || $last_3 == ' II' || $last_4 == ' III')
                                {
                                    $item_image = '1357';
                                }
                            }
                        }

                        $item_tags = rtrim($item_tags);

                        $item_wiki_name = convert_item_name_to_wiki_name($item_name);

                        $item_url = 'http://wiki.shardsofdalaya.com/index.php/' . $item_wiki_name;

                        $item_wiki_link = '<a href="' . $item_url . '">' . $item_name . '</a>';

                        //echo 'Item: ' . $item_name . '<br>';
                        //echo 'Wiki: ' . $item_wiki_link . '<br>';

                        echo 'Item: ' . $item_wiki_link . '<br>';

                        $vendor_list .= '[';

                        $vendor_list .= '"' . $character_name . '"';
                        $vendor_list .= ',';

                        $vendor_list .= '"' . $item_name . '"';
                        $vendor_list .= ',';

                        $vendor_list .= '"' . $item_image . '"';
                        $vendor_list .= ',';

                        $vendor_list .= '"' . $item_url . '"';
                        $vendor_list .= ',';

                        $vendor_list .= '"' . $item_tags . '"';
                        $vendor_list .= ',';

                        $vendor_list .= '"' . $item_hp . '"';
                        $vendor_list .= ',';

                        $vendor_list .= '"' . $item_mana . '"';
                        $vendor_list .= ',';

                        $vendor_list .= '"' . $item_ac . '"';
                        $vendor_list .= ',';

                        $vendor_list .= '"' . $item_dmg . '"';
                        $vendor_list .= ',';

                        $vendor_list .= '"' . $item_atkdelay . '"';
                        //

                        $vendor_list .= ']';
                        $vendor_list .= ',';
                    }
                }
            }

            $dump .= "\n";

            echo '<br>';
        }
    }
}

$vendor_list = substr($vendor_list, 0, -1);

$vendor_list .= ']}';

$file_date = date('ymd');

file_put_contents('data/vendor_list.txt', $vendor_list);

file_put_contents('data/history/vendor_list-' . $file_date . '.txt', $vendor_list);

$dump = rtrim($dump);

file_put_contents('data/dump.txt', $dump);

file_put_contents('data/history/dump-' . $file_date . '.txt', $dump);

$character_names = array_unique($character_names);

asort($character_names);

$character_names_list = implode("\n", $character_names);

file_put_contents('data/character_names.txt', $character_names_list);

$item_names = array_unique($item_names);

asort($item_names);

$item_names_list = implode("\n", $item_names);

file_put_contents('data/item_names.txt', $item_names_list);

echo '<h3>DONE!</h3>';

//echo "<script>window.location = 'scrape_wiki_items.php'</script>";

?>