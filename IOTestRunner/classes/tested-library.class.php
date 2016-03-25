<?php

class TestedLibrary {

    private $lang;
    private $inTestExecPath;
    private $outTestExecPath;

    public function __construct($lang, $rootLibPath, $inTestExecPath, $outTestExecPath) {
        $this->lang = $lang;
        $this->inTestExecPath = dirname(ROOT_PATH) . "/$rootLibPath/$inTestExecPath";

        if (!file_exists($this->inTestExecPath)) {
            dieLine("Nenalezen spustitelný soubor testu třídy/modulu Scanner: $this->inTestExecPath");
        }

        $this->outTestExecPath = dirname(ROOT_PATH) . "/$rootLibPath/$outTestExecPath";

        if (!file_exists($this->outTestExecPath)) {
            dieLine("Nenalezen spustitelný soubor testu třídy/modulu PrintStream: $this->outTestExecPath");
        }
    }

    public function getLang() {
        return $this->lang;
    }

    public function getInTestExecPath() {
        return $this->inTestExecPath;
    }

    public function getOutTestExecPath() {
        return $this->outTestExecPath;
    }

    public function __toString() {
        return "$this->lang knihovna";
    }

}
