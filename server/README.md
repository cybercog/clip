Install
=============================
...

Setup db
=============================
add file config/db.php:
<?php

return [
    'class' => 'yii\db\Connection',
    'dsn' => 'mysql:host=localhost;dbname=***',
    'username' => '***',
    'password' => '***',
    'charset' => 'utf8',
];

Deploy
=============================
http://flyclip.tk/deploy/dhclip.php
