var cPatterns = [
];

var cppPatterns = [
];

var csPatterns = [
    {p: /System\.in/g, r: "System_.in_"},
    {p: /System\.out/g, r: "System_.out_"},
    {p: /boolean/g, r: "bool"},
    {p: /byte/g, r: "sbyte"},
];

var pasPatterns = [
    {p: /System\.in/g, r: "System_.in_"},
    {p: /System\.out/g, r: "System_.out_"},
    {p: /long/g, r: "Int64"},
    {p: /short/g, r: "smallInt"},
    {p: /byte/g, r: "shortInt"},
    {p: /int/g, r: "longInt"},
    {p: /Int64/g, r: "int64"},
    {p: /float/g, r: "single"},
    {p: /char/g, r: "ansiChar"},
    {p: /Boolean/g, r: "Boolean_"},
    {p: /Byte/g, r: "Byte_"},
    {p: /Integer/g, r: "Integer_"},
    {p: /Double/g, r: "Double_"},
    {p: /String/g, r: "String_"},
    {p: /!=/g, r: "<>"},
    {p: /=[^=]/g, r: ":="},
    {p: /==/g, r: "="},
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