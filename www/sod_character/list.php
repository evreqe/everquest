<html>
<head>
</head>

<body>

<?php

$files = glob('characters/*.json');

foreach($files as $file)
{
    echo $file . '<br/>';

    $fileContents = file_get_contents($file);

    $character = json_decode($fileContents, true);

    foreach($character['bank']['items'] as $item)
    {
        if ($item['id'] === -1)
        {
            continue;
        }

        echo $character['name'] . ': ' . $item['name'] . '<br/>';

        $containerIsEmpty = true;

        foreach($item['containerItems'] as $containerItem)
        {
            if ($containerItem['id'] != -1)
            {
                $containerIsEmpty = false;
                break;
            }
        }

        if ($containerIsEmpty === false)
        {
            foreach($item['containerItems'] as $containerItem)
            {
                echo $character['name'] . ': ' . $containerItem['name'];

                if ($containerItem['count'] > 1)
                {
                    echo ' x ' . $containerItem['count'];
                }

                echo '<br/>';
            }
        }
    }

    foreach($character['inventory']['items'] as $item)
    {
        echo $character['name'] . ': ' . $item['name'] . '<br/>';

        $containerIsEmpty = true;

        foreach($item['containerItems'] as $containerItem)
        {
            if ($containerItem['id'] != -1)
            {
                $containerIsEmpty = false;
                break;
            }
        }

        if ($containerIsEmpty === false)
        {
            foreach($item['containerItems'] as $containerItem)
            {
                echo $character['name'] . ': ' . $containerItem['name'];

                if ($containerItem['count'] > 1)
                {
                    echo ' x ' . $containerItem['count'];
                }

                echo '<br/>';
            }
        }
    }
}

?>

</body>

</html>