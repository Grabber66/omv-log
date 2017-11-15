<?php
use OMV\System\LogFileSpec;
LogFileSpec::registerSpecification(
    'tvheadend',
    [
        'filename' => 'tvheadend',
        'filepath' => '/var/log/tvheadend.log',
        'regex" => "/^(\S+\s+\S+\s+\d+\s+\S+\s+\d+)\s+->\s+(.*)$/',
        'columns' => [
            'ts' => [
                'index' => 1,
                'func' => function ($date) {
                    return strpdate($date, 'M j G:i:s');
                },
            ],
            'date' => [
                'index' => 1,
                'func' => function ($date) {
                    return strftime('%c', strpdate($date, 'M j G:i:s'));
                },
            ],
            'event' => 3,
        ],
    ]
);
