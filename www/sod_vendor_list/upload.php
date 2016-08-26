<?php

echo '<h3>Upload</h3>';

$fpt_connection = ftp_connect('ftp.byethost16.com');

$ftp_login_result = ftp_login($fpt_connection, 'b16_15423300', 'wcoqpzee');

if ($fpt_connection && $ftp_login_result)
{
    $ftp_local_file = 'data/vendor_list.txt';

    $ftp_remote_file = 'htdocs/' . $ftp_local_file;

    $ftp_upload = ftp_put($fpt_connection, $ftp_remote_file, $ftp_local_file, FTP_BINARY);

    $ftp_chmod = ftp_site($fpt_connection, 'chmod 777 ' . $ftp_remote_file);

    $ftp_local_file = 'data/dump.txt';

    $ftp_remote_file = 'htdocs/' . $ftp_local_file;

    $ftp_upload = ftp_put($fpt_connection, $ftp_remote_file, $ftp_local_file, FTP_BINARY);

    $ftp_chmod = ftp_site($fpt_connection, 'chmod 777 ' . $ftp_remote_file);

    $ftp_local_file = 'data/character_names.txt';

    $ftp_remote_file = 'htdocs/' . $ftp_local_file;

    $ftp_upload = ftp_put($fpt_connection, $ftp_remote_file, $ftp_local_file, FTP_BINARY);

    $ftp_chmod = ftp_site($fpt_connection, 'chmod 777 ' . $ftp_remote_file);

    $ftp_local_file = 'data/item_names.txt';

    $ftp_remote_file = 'htdocs/' . $ftp_local_file;

    $ftp_upload = ftp_put($fpt_connection, $ftp_remote_file, $ftp_local_file, FTP_BINARY);

    $ftp_chmod = ftp_site($fpt_connection, 'chmod 777 ' . $ftp_remote_file);

    ftp_close($fpt_connection); 
}

echo '<h3>DONE!</h3>';

?>