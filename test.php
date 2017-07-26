<?php
use RingoLeese as RL;

//$options = RL\ProcPS::FILLCOM | RL\ProcPS::FILLSTATUS;
$options = RL\ProcPS::FILLMEM | RL\ProcPS::FILLCOM | RL\ProcPS::FILLENV;
$options|= RL\ProcPS::FILLUSR | RL\ProcPS::FILLGRP | RL\ProcPS::FILLSTATUS;
$options|= RL\ProcPS::FILLSTAT | RL\ProcPS::FILLWCHAN | RL\ProcPS::FILLARG;
$options|= RL\ProcPS::FILLCGROUP | RL\ProcPS::FILLSUPGRP | RL\ProcPS::FILLOOM;
$options|= RL\ProcPS::PID | RL\ProcPS::LOOSE_TASKS | RL\ProcPS::UID;
$options|= RL\ProcPS::FILLNS | RL\ProcPS::EDITCGRPCVT | RL\ProcPS::EDITCMDLCVT;
$options|= RL\ProcPS::EDITENVRCVT | RL\ProcPS::FILLSYSTEMD;

$procps = new RL\ProcPS();
$processes = $procps->Read($options);
print sprintf("found %d processes.\n", count($processes));

/*
foreach($processes as $process) {
	$commandLine = (isset($process['cmdline'])) ? '"'.$process['cmdline'].'"' : 'NULL';
	print 'PID: '.$process['tid'].'; Command: "'.$process['cmd'].'"; CommandLine: '.$commandLine.'; Resident Memory: '.$process['vm_rss'].'KB'."\n";
} // foreach($processes as $process)
//*/
