<link rel="stylesheet" type="text/css" href="image.css">

<div id="divmain">

<?php
$index = 1;

for ($i = 500; $i < 1463; $i++)
{
    echo '<img src="http://shardsofdalaya.com/fomelo/images/icons/item_' . $i . '.png" alt="' . $i . '" title="' . $i . '"/>';

    if ($index > 0 && $index % 16 == 0)
    {
        echo '<br>';
    }

    $index++;
}
?>

</div>