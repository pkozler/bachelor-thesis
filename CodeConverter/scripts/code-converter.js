var cPatterns = [
    {p: /\bint/g, r: "int32_t"},
    {p: /\blong/g, r: "int64_t"},
    {p: /\bshort/g, r: "int16_t"},
    {p: /\bbyte/g, r: "int8_t"},
    {p: /\bboolean/g, r: "bool"},
    {p: /\bnull/g, r: "NULL"},
    {p: /([A-Z][a-zA-z0-9_]*)\.([a-zA-z0-9_]+)/g, r: "$1_$2"},
    {p: /([a-zA-z0-9_]+)\.([a-zA-z0-9_]+)\(\s*\)/g, r: "$2($1)"},
    {p: /([a-zA-z0-9_]+)\.([a-zA-z0-9_]+)\(/g, r: "$2($1, "},
    {p: /([a-zA-z0-9_]+)\.([a-zA-z0-9_]+)/g, r: "$1->$2"},
];

var cppPatterns = [
    {p: /\bint/g, r: "int32_t"},
    {p: /\blong/g, r: "int64_t"},
    {p: /\bshort/g, r: "int16_t"},
    {p: /\bbyte/g, r: "int8_t"},
    {p: /\bboolean/g, r: "bool"},
    {p: /\bnull/g, r: "nullptr"},
    {p: /([A-Z][a-zA-z0-9_]*)\.([a-zA-z0-9_]+)/g, r: "$1::$2"},
    {p: /([a-z_][a-zA-z0-9_]*)\.([a-zA-z0-9_]+)/g, r: "$1->$2"},
];

var csPatterns = [
    {p: /System\.in/g, r: "System_.in_"},
    {p: /System\.out/g, r: "System_.out_"},
    {p: /\bboolean/g, r: "bool"},
    {p: /\bbyte/g, r: "sbyte"},
];

var pasPatterns = [
    {p: /System\.in/g, r: "System_.in_"},
    {p: /System\.out/g, r: "System_.out_"},
    {p: /\blong/g, r: "Int64"},
    {p: /\bshort/g, r: "smallInt"},
    {p: /\bbyte/g, r: "shortInt"},
    {p: /\bint/g, r: "longInt"},
    {p: /\bfloat/g, r: "single"},
    {p: /\bchar/g, r: "ansiChar"},
    {p: /\bBoolean/g, r: "Boolean_"},
    {p: /\bByte/g, r: "Byte_"},
    {p: /\bInteger/g, r: "Integer_"},
    {p: /\bDouble/g, r: "Double_"},
    {p: /\bString/g, r: "String_"},
    {p: /\bInt64/g, r: "int64"},
    {p: /!=/g, r: "<>"},
    {p: /[^=<>\+\-\*\/%]=/g, r: " := "},
    {p: /==/g, r: "="},
    {p: /\/\*/g, r: "(*"},
    {p: /\*\//g, r: "*)"},
    {p: /{/g, r: "begin"},
    {p: /}/g, r: "end;"},
    {p: /([a-zA-z0-9_]+)\s+([a-zA-z0-9_]+)\((.*)\)/g, r: "function $2($3): $1;"},
    {p: /function\s+([a-zA-z0-9_]+)\((.*)\): void;/g, r: "procedure $1($2);"},
    {p: /,/g, r: ";"},
    {p: /\b(boolean|shortInt|smallInt|longInt|int64|single|double|ansiChar)\s+([a-zA-z0-9_]+)/g, r: "$2: $1"},
    {p: /if\s*\((.*)\)\s*/g, r: "if ($1) then "},
    {p: /(\s+)do(\s+)/g, r: "$1repeat$2"},
    {p: /while\s*\((.*)\);\s*/g, r: "until ($1); "},
    {p: /while\s*\((.*)\)\s*/g, r: "while ($1) do "},
    {p: /for\s*\((.*)\)\s*/g, r: "for $1 do "},
    {p: /for\s*\((.*)\)\s*/g, r: "for $1 do "},
    {p: /([a-zA-z0-9_]+)\+\+/g, r: "inc($1)"},
    {p: /([a-zA-z0-9_]+)\-\-/g, r: "dec($1)"},
    {p: /(\s+)return (.*);/g, r: "$1exit($2);"},
];

var languages = {
    c: {name: "C", patterns: cPatterns},
    cpp: {name: "C++", patterns: cppPatterns},
    cs: {name: "C#", patterns: csPatterns},
    pas: {name: "Free Pascal", patterns: pasPatterns},
};

$(document).ready(function () {

    var wto;
    var lang = $('input[name="language"]:checked', '#lang-select').val();
    var $original = $('#original');
    var $converted = $('#converted');
    var $converting = $('#converting');

    function showMessage() {
        $converting.text("Převádím do " + languages[lang].name + " ...");
    }

    function hideMessage() {
        $converting.text("");
    }

    function convertCode() {
        var patterns = languages[lang].patterns;
        var converted = $original.val();

        for (var i = 0; i < patterns.length; i++) {
            converted = converted.replace(patterns[i].p, patterns[i].r);
        }

        $converted.val(converted);
        hideMessage();
    }

    $('#lang-select input').on('change', function () {
        lang = $('input[name="language"]:checked', '#lang-select').val();
        showMessage();
        convertCode();
    });

    $original.keydown(function () {
        clearTimeout(wto);
        showMessage();

        wto = setTimeout(function () {
            convertCode();
        }, 1000);
    });

});