<?php
require_once("openmediavault/functions.inc");
\OMV\System\LogFileSpec::registerSpecification("clamav", [
  "filename" => "clamav",
  "filepath" => "/var/log/clamav/clamav.log",
  "regex" => "/^(\S+\s+\S+\s+\d+\s+\S+\s+\d+)\s+->\s+(.*)$/",
  "columns" => [
	  "ts" => [
		  "index" => 1,
		  "func" => function($v) { return strpdate($v,"D M j H:i:s Y"); }
	  ],
	  "date" => [
		  "index" => 1,
		  "func" => function($v) {
			  return strftime("%c", strpdate($v,"D M j H:i:s Y"));
		  }
	  ],
	  "message" => 2
  ]]);
