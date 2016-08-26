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

include('simple_html_dom.php');

set_time_limit(0); // prevent maximum execution time timeout

echo '<h3>Scrape Wiki Items</h3>';

$file_get_context = stream_context_create(array('http' => array('header' => 'Connection: close')));

$file = fopen("data/item_names.txt", "r");

if ($file)
{
    while (($item_name = fgets($file)) !== false)
    {
        $item_name = rtrim($item_name);

        if (file_exists('items/' . md5($item_name) . '.txt'))
        {
            echo 'Item file already exists: ' . $item_name . '<br>';

            continue;
        }

        // skip spells and songs because they do not have stats that are scraped yet
        if (strpos($item_name, 'Spell:') !== false || strpos($item_name, 'Song:') !== false)
        {
            echo 'Item is a Spell or Song, skipping it: ' . $item_name . '<br>';

            continue;
        }

        $item_wiki_name = convert_item_name_to_wiki_name($item_name);

        $item_wiki_name = fix_item_name($item_wiki_name);

        $url = 'http://wiki.shardsofdalaya.com/index.php?title=' . $item_wiki_name . '&action=edit';

        echo '----------------------------------------------------------------------------------------------------<br>';

        echo '<a href="' . $url . '">' . $item_name . '</a><br>';

        $html = file_get_html($url, false, $file_get_context);

        if (strpos($html, '{{Itemstats') === false)
        {
            echo 'Item stats not found or item is using outdated format: ' . $item_name . '<br>';

            echo '----------------------------------------------------------------------------------------------------<br>';

            continue;
        }

        $item_stats = '';

        // find the {{Itemstats text box
        foreach ($html->find('textarea') as $textarea)
        {
            if (strpos($textarea->id, 'wpTextbox1') !== false)
            {
                //echo $textarea->plaintext . '<br>';

                $item_stats = $textarea->plaintext;

                break;
            }
        }

        $item_stats_custom = '[item]' . "\n";

        // name
        if (preg_match('/\|\s+name\s+=\s+([\w |\'|`]+)/', $item_stats, $matches))
        {
            echo 'name=' . $matches[1] . '<br>';
        }

        $item_stats_custom .= 'name=' . '"' . $item_name . '"'. "\n";

        // image
        if (preg_match('/\|\s+image\s+=\s+(\d+)/', $item_stats, $matches))
        {
            echo 'image=' . $matches[1] . '<br>';

            $item_stats_custom .= 'image=' . $matches[1] . "\n";
        }

        // flagboe
        if (preg_match('/\|\s+flagboe\s+=\s+(\d+)/', $item_stats, $matches))
        {
            echo 'flagboe=' . $matches[1] . '<br>';

            $item_stats_custom .= 'flagboe=' . $matches[1] . "\n";
        }

        // flaglore
        if (preg_match('/\|\s+flaglore\s+=\s+(\d+)/', $item_stats, $matches))
        {
            echo 'flaglore=' . $matches[1] . '<br>';

            $item_stats_custom .= 'flaglore=' . $matches[1] . "\n";
        }

        // flagmagic
        if (preg_match('/\|\s+flagmagic\s+=\s+(\d+)/', $item_stats, $matches))
        {
            echo 'flagmagic=' . $matches[1] . '<br>';

            $item_stats_custom .= 'flagmagic=' . $matches[1] . "\n";
        }

        // flagaug
        if (preg_match('/\|\s+flagaug\s+=\s+(\d+)/', $item_stats, $matches))
        {
            echo 'flagaug=' . $matches[1] . '<br>';

            $item_stats_custom .= 'flagaug=' . $matches[1] . "\n";
        }

        // container
        if (preg_match('/\|\s+container\s+=\s+(\d+)/', $item_stats, $matches))
        {
            echo 'container=' . $matches[1] . '<br>';

            $item_stats_custom .= 'container=' . $matches[1] . "\n";
        }

        // health
        if (preg_match('/\|\s+health\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'health=' . $matches[1] . '<br>';

            $item_stats_custom .= 'health=' . $matches[1] . "\n";
        }

        // mana
        if (preg_match('/\|\s+mana\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'mana=' . $matches[1] . '<br>';

            $item_stats_custom .= 'mana=' . $matches[1] . "\n";
        }

        // ac
        if (preg_match('/\|\s+ac\s+=\s+(\d+)/', $item_stats, $matches))
        {
            echo 'ac=' . $matches[1] . '<br>';

            $item_stats_custom .= 'ac=' . $matches[1] . "\n";
        }

        // dmg
        if (preg_match('/\|\s+dmg\s+=\s+(\d+)/', $item_stats, $matches))
        {
            echo 'dmg=' . $matches[1] . '<br>';

            $item_stats_custom .= 'dmg=' . $matches[1] . "\n";
        }

        // atkdelay
        if (preg_match('/\|\s+atkdelay\s+=\s+(\d+)/', $item_stats, $matches))
        {
            echo 'atkdelay=' . $matches[1] . '<br>';

            $item_stats_custom .= 'atkdelay=' . $matches[1] . "\n";
        }

        // str
        if (preg_match('/\|\s+str\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'str=' . $matches[1] . '<br>';

            $item_stats_custom .= 'str=' . $matches[1] . "\n";
        }

        // sta
        if (preg_match('/\|\s+sta\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'sta=' . $matches[1] . '<br>';

            $item_stats_custom .= 'sta=' . $matches[1] . "\n";
        }

        // agi
        if (preg_match('/\|\s+agi\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'agi=' . $matches[1] . '<br>';

            $item_stats_custom .= 'agi=' . $matches[1] . "\n";
        }

        // dex
        if (preg_match('/\|\s+dex\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'dex=' . $matches[1] . '<br>';

            $item_stats_custom .= 'dex=' . $matches[1] . "\n";
        }

        // wis
        if (preg_match('/\|\s+wis\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'wis=' . $matches[1] . '<br>';

            $item_stats_custom .= 'wis=' . $matches[1] . "\n";
        }

        // int
        if (preg_match('/\|\s+int\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'int=' . $matches[1] . '<br>';

            $item_stats_custom .= 'int=' . $matches[1] . "\n";
        }

        // cha
        if (preg_match('/\|\s+cha\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'cha=' . $matches[1] . '<br>';

            $item_stats_custom .= 'cha=' . $matches[1] . "\n";
        }

        // svfire
        if (preg_match('/\|\s+svfire\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'svfire=' . $matches[1] . '<br>';

            $item_stats_custom .= 'svfire=' . $matches[1] . "\n";
        }

        // svcold
        if (preg_match('/\|\s+svcold\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'svcold=' . $matches[1] . '<br>';

            $item_stats_custom .= 'svcold=' . $matches[1] . "\n";
        }

        // svmagic
        if (preg_match('/\|\s+svmagic\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'svmagic=' . $matches[1] . '<br>';

            $item_stats_custom .= 'svmagic=' . $matches[1] . "\n";
        }

        // svdisease
        if (preg_match('/\|\s+svdisease\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'svdisease=' . $matches[1] . '<br>';

            $item_stats_custom .= 'svdisease=' . $matches[1] . "\n";
        }

        // svpoison
        if (preg_match('/\|\s+svpoison\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'svpoison=' . $matches[1] . '<br>';

            $item_stats_custom .= 'svpoison=' . $matches[1] . "\n";
        }

        // skill
        if (preg_match('/\|\s+skill\s+=\s+([\w |\'|`]+)/', $item_stats, $matches))
        {
            echo 'skill=' . $matches[1] . '<br>';

            $item_stats_custom .= 'skill=' . '"' . $matches[1] . '"' . "\n";
        }

        // focuseffect
        if (preg_match('/\|\s+focuseffect\s+=\s+([\w |\'|`]+)/', $item_stats, $matches))
        {
            echo 'focuseffect=' . $matches[1] . '<br>';

            $item_stats_custom .= 'focuseffect=' . '"' . $matches[1] . '"' . "\n";
        }

        // effect
        if (preg_match('/\|\s+effect\s+=\s+([\w |\'|`]+)/', $item_stats, $matches))
        {
            echo 'effect=' . $matches[1] . '<br>';

            $item_stats_custom .= 'effect=' . '"' . $matches[1] . '"' . "\n";
        }

        // effectflag
        if (preg_match('/\|\s+effectflag\s+=\s+([\w |\'|`]+)/', $item_stats, $matches))
        {
            echo 'effectflag=' . $matches[1] . '<br>';

            $item_stats_custom .= 'effectflag=' . '"' . $matches[1] . '"' . "\n";
        }

        // aggression
        if (preg_match('/\|\s+aggression\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'aggression=' . $matches[1] . '<br>';

            $item_stats_custom .= 'aggression=' . $matches[1] . "\n";
        }

        // critstrike
        if (preg_match('/\|\s+critstrike\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'critstrike=' . $matches[1] . '<br>';

            $item_stats_custom .= 'critstrike=' . $matches[1] . "\n";
        }

        // dmgreduction
        if (preg_match('/\|\s+dmgreduction\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'dmgreduction=' . $matches[1] . '<br>';

            $item_stats_custom .= 'dmgreduction=' . $matches[1] . "\n";
        }

        // flowingthought
        if (preg_match('/\|\s+flowingthought\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'flowingthought=' . $matches[1] . '<br>';

            $item_stats_custom .= 'flowingthought=' . $matches[1] . "\n";
        }

        // mindshield
        if (preg_match('/\|\s+mindshield\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'mindshield=' . $matches[1] . '<br>';

            $item_stats_custom .= 'mindshield=' . $matches[1] . "\n";
        }

        // spellward
        if (preg_match('/\|\s+spellward\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'spellward=' . $matches[1] . '<br>';

            $item_stats_custom .= 'spellward=' . $matches[1] . "\n";
        }

        // stunresist
        if (preg_match('/\|\s+stunresist\s+=\s+([+-]?\d+)/', $item_stats, $matches))
        {
            echo 'stunresist=' . $matches[1] . '<br>';

            $item_stats_custom .= 'stunresist=' . $matches[1] . "\n";
        }

        // tradeskilled
        if (preg_match('/\|\s+tradeskilled\s+=\s+([\w |\'|`]+)/', $item_stats, $matches))
        {
            echo 'tradeskilled=' . $matches[1] . '<br>';

            $item_stats_custom .= 'tradeskilled=' . '"' . $matches[1] . '"' . "\n";
        }

        // insttypemod
        if (preg_match('/\|\s+insttypemod\s+=\s+([\w |\'|`]+)/', $item_stats, $matches))
        {
            echo 'insttypemod=' . $matches[1] . '<br>';

            $item_stats_custom .= 'insttypemod=' . '"' . $matches[1] . '"' . "\n";
        }

        // spdmgtype
        if (preg_match('/\|\s+spdmgtype\s+=\s+([\w |\'|`]+)/', $item_stats, $matches))
        {
            echo 'spdmgtype=' . $matches[1] . '<br>';

            $item_stats_custom .= 'spdmgtype=' . '"' . $matches[1] . '"' . "\n";
        }

        // skillmod
        if (preg_match('/\|\s+skillmod\s+=\s+([\w |\'|`]+)/', $item_stats, $matches))
        {
            echo 'skillmod=' . $matches[1] . '<br>';

            $item_stats_custom .= 'skillmod=' . '"' . $matches[1] . '"' . "\n";
        }

        // wt
        if (preg_match('/\|\s+wt\s+=\s+(\d+\.?\d+?)/', $item_stats, $matches))
        {
            echo 'wt=' . $matches[1] . '<br>';

            $item_stats_custom .= 'wt=' . $matches[1] . "\n";
        }

        // wtreduc
        if (preg_match('/\|\s+wtreduc\s+=\s+(\d+)/', $item_stats, $matches))
        {
            echo 'wtreduc=' . $matches[1] . '<br>';

            $item_stats_custom .= 'wtreduc=' . $matches[1] . "\n";
        }

        // size
        if (preg_match('/\|\s+size\s+=\s+(\w+)/', $item_stats, $matches))
        {
            echo 'size=' . $matches[1] . '<br>';

            $item_stats_custom .= 'size=' . strtoupper($matches[1]) . "\n";
        }

        // reclvl
        if (preg_match('/\|\s+reclvl\s+=\s+(\d+)/', $item_stats, $matches))
        {
            echo 'reclvl=' . $matches[1] . '<br>';

            $item_stats_custom .= 'reclvl=' . $matches[1] . "\n";
        }

        if (strpos($item_name, '10 Dose') === false && strpos($item_stats, 'flagaug') === false) // skip potions and augs
        {
            // slots
            if (preg_match_all('/\|\s+slot\d+\s+=\s+((\w+))/', $item_stats, $matches))
            {
                //print_r($matches);

                $slots = 'slots=';

                for ($i = 0; $i < count($matches[0]); $i++)
                {
                    $slots .= strtoupper($matches[2][$i]);

                    if ($i < count($matches[0]) - 1)
                    {
                        $slots .= ',';
                    }
                }

                echo $slots . '<br>';

                $item_stats_custom .= $slots . "\n";
            }

            // classes
            if (preg_match_all('/\|\s+class\d+\s+=\s+((\w+))/', $item_stats, $matches))
            {
                //print_r($matches);

                $classes = 'classes=';

                for ($i = 0; $i < count($matches[0]); $i++)
                {
                    $classes .= $matches[2][$i];

                    if ($i < count($matches[0]) - 1)
                    {
                        $classes .= ',';
                    }
                }

                echo $classes . '<br>';

                $item_stats_custom .= $classes . "\n";
            }

            // races
            if (preg_match_all('/\|\s+race\d+\s+=\s+((\w+))/', $item_stats, $matches))
            {
                //print_r($matches);

                $races = 'races=';

                for ($i = 0; $i < count($matches[0]); $i++)
                {
                    $races .= $matches[2][$i];

                    if ($i < count($matches[0]) - 1)
                    {
                        $races .= ',';
                    }
                }

                echo $races . '<br>';

                $item_stats_custom .= $races . "\n";
            }
        }

        echo '----------------------------------------------------------------------------------------------------<br>';

        //break;

        $item_stats_custom = rtrim($item_stats_custom);

        file_put_contents('items/' . md5($item_name) . '.txt', $item_stats_custom);
    }
}

fclose($file);

echo '<h3>DONE!</h3>';

//echo "<script>window.location = 'scrape_vendor_list.php'</script>";

?>