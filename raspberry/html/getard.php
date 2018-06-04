<?php
$myfile = fopen("newfile.txt", "a") or die("Unable to open file!");

$a=$_GET['aid'];
$data=sprintf('%s',$a);
fwrite($myfile, $data.PHP_EOL);
fclose($myfile);
?>
