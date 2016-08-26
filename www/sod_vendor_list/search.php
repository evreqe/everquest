<?php
$item_name = $_POST["itemname"];
$item_tags = $_POST["itemtags"];

$item_tags = split(' ', $item_tags);
?>

<form method="post" action="<?php echo $PHP_SELF;?>">
Item Name:
<input type="text" name="itemname">
Item Tags:
<input type="text" name="itemtags">
<input type="submit" value="Search" name="submit">
</form>

<p>
Search results for:
<?php
echo $_POST["itemname"];
echo ' (' . $_POST["itemtags"] . ')';
?>
</p>

<table border="1">

<tr>
<th>File</th>
<th>Name</th>
<th>Item Name</th>
<th>Item Tags</th>
</tr>

<?php
$files = scandir('data/history');

$files = array_reverse($files);

foreach ($files as $file)
{
    if (strpos($file, 'vendor_list') !== false)
    {
        $file_contents = file_get_contents('data/history/' . $file);

        $file_contents_array = json_decode($file_contents);

        $data = $file_contents_array->data;

        foreach ($data as $d)
        {
            if (stripos($d[1], $item_name) !== false)
            {
                echo '<tr>';
                echo '<td>' . $file . '</td>';
                echo '<td>' . $d[0] . '</td>';
                echo '<td>' . '<a href="' . $d[3] . '">' . $d[1] . '</a>' . '</td>';
                echo '<td>&nbsp;</td>';
                echo '</tr>';
            }

            $found_tags = false;

            foreach ($item_tags as $item_tag)
            {
                if (stripos($d[4], $item_tag) === false)
                {
                    $found_tags = false;
                    break;
                }
                else
                {
                    $found_tags = true;
                }
            }

            if ($found_tags == true)
            {
                echo '<tr>';
                echo '<td>' . $file . '</td>';
                echo '<td>' . $d[0] . '</td>';
                echo '<td>' . '<a href="' . $d[3] . '">' . $d[1] . '</a>' . '</td>';
                echo '<td>';
                foreach ($item_tags as $item_tag)
                {
                    echo $item_tag . ' ';
                }
                echo '</td>';
                echo '</tr>';
            }
        }
    }
}
?>

</table>

<p>
<a href="#top">Top</a>
</p>
