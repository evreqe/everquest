<?php

$file = fopen("data/item_names.txt", "r");

if ($file)
{
    while (($item_name = fgets($file)) !== false)
    {
        $item_name = rtrim($item_name);

        $item_filename = 'items/' . md5($item_name) . '.txt';

        if (file_exists($item_filename))
        {
            $item_stats = parse_ini_file($item_filename);

            //print_r($item_stats);

            //foreach ($item_stats as $key => $val)
            //{
                //echo $key . ': ' . $val . '<br>';
            //}

            if (array_key_exists('image', $item_stats))
            {
                echo $item_stats['image'] . '<br>';
            }

            if (array_key_exists('races', $item_stats))
            {
                $item_races = $item_stats['races'];

                $item_races = str_replace(',', ' ', $item_races);

                $item_tags = $item_races;

                echo $item_tags . '<br>';
            }
            else
            {
                echo 'races not found' . '<br>';
            }

            echo '<br><br>';
        }
    }
}

fclose($file);

?>