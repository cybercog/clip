Install
=============================
...

Setup db
=============================
add file config/db.php:
<?php

return [
    'class' => 'yii\db\Connection',
    'dsn' => 'mysql:host=localhost;dbname=*',
    'username' => '*',
    'password' => '*',
    'charset' => 'utf8',
];

Setup mailer
'mailer' => [
    'class' => 'yii\swiftmailer\Mailer',
    'useFileTransport' => false,
    'messageConfig' => [
        'from' => ['info@*.ru' => 'Info Forsk'], // this is needed for sending emails
        'charset' => 'UTF-8',
    ],
    'transport' => [
        'class' => 'Swift_SmtpTransport',
        'host' => '*.ru',
        'username' => 'info@*.ru',
        'password' => '*',
        'port' => '587',
        'encryption' => 'tls',
    ],
],


Deploy
=============================
http://flyclip.tk/deploy/dhclip.php
