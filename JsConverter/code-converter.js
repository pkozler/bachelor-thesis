$(document).ready(function(){

	var wto;
	var lang = $('input[name="language"]:checked', '#lang-select').val();
	var $original = $('#original');
	var $converted = $('#converted');

	function convertToC(original) {
		return original;
	}

	function convertToCpp(original) {
		return original;
	}

	function convertToCs(original) {
		var converted = original.replace(/System\.in/g, "System_.in_");
		converted = converted.replace(/System\.out/g, "System_.out_");
		converted = converted.replace(/boolean/g, "bool");
		converted = converted.replace(/byte/g, "sbyte");
		return converted;
	}

	function convertToPas(original) {
		return original;
	}

	var langNames = {};
	langNames["c"] = { name:"C", convertor:convertToC };
	langNames["cpp"] = { name:"C++", convertor:convertToCpp };
	langNames["cs"] = { name:"C#", convertor:convertToCs };
	langNames["pas"] = { name:"Free Pascal", convertor:convertToPas };

	function showMessage() {
		$converted.val("Převádím do " + langNames[lang].name + " ...");
	}

	function convertCode() {
		$converted.val(langNames[lang].convertor($original.val()));
	}

	$('#lang-select input').on('change', function() {
	   lang = $('input[name="language"]:checked', '#lang-select').val();
	   showMessage();
	   convertCode();
	});

	$original.keydown(function() {
	  clearTimeout(wto);
	  showMessage();
	  wto = setTimeout(function() {
	    convertCode();
	  }, 1000);
	});

});