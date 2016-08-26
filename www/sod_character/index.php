<html>
<head>
    <link rel="stylesheet" type="text/css" href="index.css">

    <link rel="stylesheet" href="//code.jquery.com/ui/1.11.4/themes/smoothness/jquery-ui.css">
    <script src="//code.jquery.com/jquery-1.12.0.min.js"></script>
    <script src="//code.jquery.com/ui/1.11.4/jquery-ui.js"></script>

    <style type="text/css">
        .ui-tooltip
        {
            white-space: pre-line;
        }
    </style>

    <script>
        $(function()
        {
            $(document).tooltip();
        });
    </script>
</head>

<body>

<?php
$character_name = $_POST["charactername"];
?>

<form method="post" action="<?php echo $PHP_SELF;?>">
<input type="text" name="charactername">
<input type="submit" value="Search" name="submit">
</form>

<?php

$file = file_get_contents('characters\\' . $character_name . '.json');

$character = json_decode($file, true);

echo '<p>Name: ' . $character['name'] . '</p>';

echo '<h3>Bank</h3>';

echo '<p>';
echo 'Platinum: ' . $character['bank']['currency']['platinum'] . '<br>';
echo 'Gold: ' . $character['bank']['currency']['gold'] . '<br>';
echo 'Silver: ' . $character['bank']['currency']['silver'] . '<br>';
echo 'Copper: ' . $character['bank']['currency']['copper'] . '<br>';
echo '</p>';

foreach($character['bank']['items'] as $item)
{
    if ($item['id'] === -1)
    {
        continue;
    }

    echo '<div style="float: left; margin: 10px; height: 240px;">';

    if ($item['icon'] === -1)
    {
        $itemImageUrl = 'images/slot.png';
    }
    else
    {
        $itemImageUrl  = 'https://www.shardsofdalaya.com/fomelo/images/icons/item_' . $item['icon'] . '.png';
    }

    $itemToolTip = $item['name'];

    if ($item['nodrop'] == 1)
    {
        $itemToolTip .= '&#013;[NO DROP]';
    }

    echo '<img src="' . $itemImageUrl  . '" title="' . $itemToolTip . '" class="slot"/><br />';

    $containerIsEmpty = true;

    foreach($item['container_items'] as $containerItem)
    {
        if ($containerItem['id'] != -1)
        {
            $containerIsEmpty = false;
            break;
        }
    }

    if ($containerIsEmpty === false)
    {
        foreach($item['container_items'] as $containerItem)
        {
            if ($containerItem['icon'] === -1)
            {
                $containerItemImageUrl = 'images/slot.png';
            }
            else
            {
                $containerItemImageUrl = 'https://www.shardsofdalaya.com/fomelo/images/icons/item_' . $containerItem['icon'] . '.png';
            }

            echo '<div style="float: left; position: relative; clear: none; overflow: hidden;">';

            $containerItemToolTip = $containerItem['name'];

            if ($containerItem['nodrop'] == 1)
            {
                $containerItemToolTip .= '&#013;[NO DROP]';
            }

            echo '<img src="' . $containerItemImageUrl . '" title="'. $containerItemToolTip . '" class="slot"/>';

            if ($containerItem['count'] > 1)
            {
                echo '<p class="slottext">' . $containerItem['count'] . '</p>';
            }

            echo '</div>';

            if ($containerItem['slot'] % 2 == 0)
            {
                echo '<div style="clear: both;"></div>';
            }
        }
    }

    echo '</div>';
}

echo '<div style="clear: both;"></div>';

echo '<h3>Inventory</h3>';

echo '<p>';
echo 'Platinum: ' . $character['inventory']['currency']['platinum'] . '<br>';
echo 'Gold: ' . $character['inventory']['currency']['gold'] . '<br>';
echo 'Silver: ' . $character['inventory']['currency']['silver'] . '<br>';
echo 'Copper: ' . $character['inventory']['currency']['copper'] . '<br>';
echo '</p>';

foreach($character['inventory']['items'] as $item)
{
    if ($item['slot'] === 24)
    {
        echo '<div style="clear: both;"></div>';
    }

    if ($item['slot'] < 24)
    {
        echo '<div style="float: left; margin: 10px;">';
    }
    else
    {
        echo '<div style="float: left; margin: 10px; height: 240px;">';
    }

    if ($item['icon'] === -1)
    {
        $itemImageUrl = 'images/slot' . $item['slot'] . '.png';
    }
    else
    {
        $itemImageUrl = 'https://www.shardsofdalaya.com/fomelo/images/icons/item_' . $item['icon'] . '.png';

        //$itemIconFile = 'icons/' . $item['icon'] . '.png';

        //file_put_contents($itemIconFile, file_get_contents($itemImageUrl));
    }

    $itemToolTip = $item['slot_name'] . ': ' . $item['name'];

    if ($item['nodrop'] == 1)
    {
        $itemToolTip .= '&#013;[NO DROP]';
    }

    echo '<img src="' . $itemImageUrl . '" title="'. $itemToolTip . '" class="slot"/><br />';

    $containerIsEmpty = true;

    foreach($item['container_items'] as $containerItem)
    {
        if ($containerItem['id'] != -1)
        {
            $containerIsEmpty = false;
            break;
        }
    }

    if ($containerIsEmpty === false)
    {
        foreach($item['container_items'] as $containerItem)
        {
            if ($item['slot'] < 24 && $containerItem['id'] === -1)
            {
                continue;
            }

            if ($containerItem['icon'] === -1)
            {
                $containerItemImageUrl = 'images/slot.png';
            }
            else
            {
                $containerItemImageUrl = 'https://www.shardsofdalaya.com/fomelo/images/icons/item_' . $containerItem['icon'] . '.png';

                //$containerItemIconFile = 'icons/' . $containerItem['icon'] . '.png';

                //file_put_contents($containerItemIconFile, file_get_contents($containerItemImageUrl));
            }

            echo '<div style="float: left; position: relative; clear: none; overflow: hidden;">';

            $containerItemToolTip = $containerItem['name'];

            if ($containerItem['nodrop'] == 1)
            {
                $containerItemToolTip .= '&#013;[NO DROP]';
            }

            echo '<img src="' . $containerItemImageUrl . '" title="'. $containerItemToolTip . '" class="slot"/>';

            if ($containerItem['count'] > 1)
            {
                echo '<p class="slottext">' . $containerItem['count'] . '</p>';
            }

            echo '</div>';

            if ($containerItem['slot'] % 2 == 0)
            {
                echo '<div style="clear: both;"></div>';
            }
        }
    }

    echo '</div>';
}

echo '<div style="clear: both;"></div>';

echo '<div style="height: 100px;"></div>';

?>

</body>

</html>