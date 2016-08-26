<h1>Vendor List History</h1>

<?php

$files = scandir('data/history');

foreach ($files as $file)
{
    if (strpos($file, 'vendor_list') !== false)
    {
        echo '<a href="index.php?history=' . $file . '">' . $file . '</a><br>';
    }
}

?>