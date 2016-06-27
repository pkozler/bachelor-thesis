program SeznamSlov;

const
  (* Maximalni pocet ruznych slov ziskanych ze vstupniho textu *)
  MAXIMALNI_POCET_RUZNYCH_SLOV = 25000;

type
  TRuznaSlova = array[0..MAXIMALNI_POCET_RUZNYCH_SLOV] of ansistring;
  
var
  (* Ruzna slova ziskana ze vstupniho tetu *)
  ruznaSlova: TRuznaSlova;
  (* Pocet ruznych slov ziskanych ze vstupniho textu *)
  pocetRuznychSlov: longint;
  radka: ansistring;

(*
 * Vlozi zadane slovo do pole ruznych slov, pokud toto slovo v poli jeste neni obsazene
 * @param slovo slovo, ktere ma byt vlozeno do pole ruznych slov
 *)        
procedure zaradSlovo(slovo: ansistring);
var
  nalezeno: boolean;
  i: longint;
  
begin  
  nalezeno := false;
  for i := 0 to (pocetRuznychSlov - 1) do begin
    if (ruznaSlova[i] = slovo) then begin
      nalezeno := true;
      break;
    end;
  end;
  
  if (NOT nalezeno) then begin
    ruznaSlova[pocetRuznychSlov] := slovo;
    inc(pocetRuznychSlov);
  end;
end;

(*
 * Function, which determines whether the specified character is a letter or not.
 * @return <code>true</code>, if the specified character is a letter or <code>false</code> otherwise
 *)
function isLetter(character: char): boolean;
begin
  if (((character >= 'A') AND (character <= 'Z')) OR ((character >= 'a') AND (character <= 'z'))) then begin
    isLetter := true;
  end
  else begin
    isLetter := false;
  end;
end;

(*
 * Zpracuje zadanou radku textu - najde vsechna slova (skupiny pismen) a vlozi je do pole slov, pokud tato slova jeste nejsou v poli obsazena
 * @param radka radka texti, z niz se maji ziskat slova
 *)        
procedure zpracujRadku(radka: ansistring);
var
  slovo: ansistring;
  zacatekSlova: longint;
  pocetZnaku: longint;
  i: longint;

begin
  zacatekSlova := -1;
  pocetZnaku := -1;
      
  for i := 1 to length(radka) do begin
    if ((pocetZnaku <= 0) AND (isLetter(radka[i]))) then begin //Slovo zacina pismenem
      zacatekSlova := i;
      pocetZnaku := 1;
    end
    else if ((pocetZnaku > 0) AND (isLetter(radka[i]))) then begin //Pismena uvnitr slova
      inc(pocetZnaku);
      
      if (i = length(radka)) then begin // Pro slova na konci radky
        slovo := copy(radka, zacatekSlova, pocetZnaku);
        zaradSlovo(lowerCase(slovo));
        zacatekSlova := -1;
        pocetZnaku := -1;
      end;
    end
    else if ((pocetZnaku > 0) AND (NOT isLetter(radka[i]))) then begin //Slovo konci nepismenem
      slovo := copy(radka, zacatekSlova, pocetZnaku);
      zaradSlovo(lowerCase(slovo));
      zacatekSlova := -1;
      pocetZnaku := -1;
    end;
  end;
end;

(*
 * Seradi naplnene pole ruznych slov pomoci SelectSort
 *)     
procedure seradRuznaSlova();
var
  index: longint;
  pom: ansistring;
  i, j: longint;
  
begin
  for i := 0 to (pocetRuznychSlov - 2) do begin
    index := i;
    
    for j := i to (pocetRuznychSlov - 1) do begin
      if (ruznaSlova[j] < ruznaSlova[index]) then begin
        index := j;
      end;
    end;
    
    if (index <> i) then begin
      pom := ruznaSlova[i];
      ruznaSlova[i] := ruznaSlova[index];
      ruznaSlova[index] := pom;
    end;
  end;
end;

(*
 *  Vypise pole ruznych slov na standardni vystup (jedno slovo na jeden radek)
 *)     
procedure vypisRuznaSlova();
var 
  i: longint;
begin
  for i := 0 to (pocetRuznychSlov - 1) do begin
    writeln(ruznaSlova[i]);
  end;
end;

(*
 * Vstupni bod programu
 *)
begin
  pocetRuznychSlov := 0;
  
  readln(radka);
  while (radka <> ('.')) do begin  //Dokud neni nalezena samotna tecka na samotne radce
    zpracujRadku(radka);
    readln(radka);
  end;
  
  seradRuznaSlova();
  vypisRuznaSlova();
end.