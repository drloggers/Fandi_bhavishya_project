#sanket perl file for report generation
@trace_list = (
    'DIST-FP-1',
    'DIST-FP-2',
    'DIST-FP-3',
    'DIST-FP-4',
    'DIST-FP-5',
    'DIST-INT-1',
    'DIST-INT-2',
    'DIST-INT-3',
    'DIST-INT-4',
    'DIST-INT-5',
    'DIST-MM-1',
    'DIST-MM-2',
    'DIST-MM-3',
    'DIST-MM-4',
    'DIST-MM-5',
    'DIST-SERV-1',
    'DIST-SERV-2',
    'DIST-SERV-3',
    'DIST-SERV-4',
    'DIST-SERV-5'
);

foreach $trace (@trace_list) {
    print $trace, "\n";
    $output = `./predictor traces/$trace`;
    print $output;
    print "\n";
}

