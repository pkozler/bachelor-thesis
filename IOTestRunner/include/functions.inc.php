<?php

/*
 *	Helper function definitions.
 */

/*
	Prints the specified string with terminating the line.
 */
function echoLine($str = "") {
    echo("$str\n");
}

/*
	Prints the specified string with terminating the line
	and terminates the program.
 */
function dieLine($str = "") {
    die("$str\n");
}
