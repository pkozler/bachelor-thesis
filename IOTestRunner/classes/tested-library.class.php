<?php

/**
 * This class represents the containers for storing names
 * of the supported programming languages with paths to the
 * executable files of their IO library testing utilities.
 *
 * @author Petr Kozler
 */
class TestedLibrary {

    // language name
    private $lang;
    // path to the executable file of the input library (Scanner) testing utility
    private $inTestExecPath;
    // path to the executable file of the output library (PrintStream) testing utility
    private $outTestExecPath;

    /**
     * Creates the new container.
     *
     * @param $lang a language name
     * @param $rootLibPath a common root path to the executable files of the library testing utilities
     * @param $inTestExecPath a path to the executable file of the input library testing utility
     * @param $outTestExecPath a path to the executable file of the output library testing utility
     */
    public function __construct($lang, $rootLibPath, $inTestExecPath, $outTestExecPath) {
        $this->lang = $lang;
        $this->inTestExecPath = dirname(ROOT_PATH) . "/$rootLibPath/$inTestExecPath";

        // input testing utility not found
        if (!file_exists($this->inTestExecPath)) {
            dieLine("Nenalezen spustitelný soubor testu třídy/modulu Scanner: $this->inTestExecPath");
        }

        $this->outTestExecPath = dirname(ROOT_PATH) . "/$rootLibPath/$outTestExecPath";

        // output testing utility not found
        if (!file_exists($this->outTestExecPath)) {
            dieLine("Nenalezen spustitelný soubor testu třídy/modulu PrintStream: $this->outTestExecPath");
        }
    }

    /**
     * Returns the language name.
     *
     * @return the language name
     */
    public function getLang() {
        return $this->lang;
    }

    /**
     * Returns the path to the executable file of the input library testing utility.
     *
     * @return the executable file path
     */
    public function getInTestExecPath() {
        return $this->inTestExecPath;
    }

    /**
     * Returns the path to the executable file of the output library testing utility.
     *
     * @return the executable file path
     */
    public function getOutTestExecPath() {
        return $this->outTestExecPath;
    }

    /**
     * Returns the string representation of the container object.
     *
     * @return the string representation
     */
    public function __toString() {
        return "$this->lang knihovna";
    }

}
