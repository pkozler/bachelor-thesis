program Palindromy;

const
  POCET_ZNAKU = 21;

type 
  TZnaky = array[0..POCET_ZNAKU - 1] of char;

var
  znaky: TZnaky;
  znakyOpacne: TZnaky;
  pocetRetezcu: longint;
  retezec: ansistring;
  i: longint;

(*
 * Najde a vrati index zadaneho znaku v poli znaku, ktere jsou povolene a zaroven maji znaky opacne
 * @param znak znak, ktery ma byt nalezen v poli znaku
 * @return index zadaneho znaku v poli znaku, nebo -1, pokud znak nebyl v poli znaku nalezen   
 *)        
function najdiIndexZnaku(znak: char): longint;
var
  dolniMez: longint;
  horniMez: longint;
  stred: longint;
begin
  dolniMez := 0;
  horniMez := length(znaky) - 1;
  stred := 0;
  
  while (dolniMez <= horniMez) do begin
    stred := (dolniMez + horniMez) div 2;
    
    if (znaky[stred] < znak) then begin
      dolniMez := stred + 1;
    end 
    else if (znaky[stred] > znak) then begin
      horniMez := stred - 1;
    end                       
    else begin
      najdiIndexZnaku := stred;
      exit;
    end;
  end;
  
  najdiIndexZnaku := -1;
end;

(*
 * Vrati <code>true</code>, pokud znak1 je opacny ke znaku znak2 (a naopak). Jinak vraci <code>false</code>.
 * @param znak1 prvni znak
 * @param znak2 druhy znak
 * @return <code>true</code>, pokud znak1 je opacny ke znaku znak2 (a naopak). Jinak <code>false</code>.
 *)              
function jsouZnakyOpacne(znak1: char; znak2: char): boolean;
var
  index: longint;
  
begin
  index := najdiIndexZnaku(znak1);
  
  if (index >= 0) then begin
    jsouZnakyOpacne := (znakyOpacne[index] = znak2);
  end
  else begin
    jsouZnakyOpacne := false;
  end;
end;

(*
 * Urci typ retezce (retezec, palindrom, zrcadlovy retezec, zrcadlovy palindrom) a vrati ho spolecne s retezcem
 * @param retezec retezec, u ktereho ma byt urcten typ
 * @return typ retezce (retezec, palindrom, zrcadlovy retezec, zrcadlovy palindrom) spolecne s retezcem
 *)           
function urciTypRetezce(retezec: ansistring): ansistring;
var
  palindrom: boolean;
  zrcadlovy: boolean;
  chybaPalindrom: boolean;
  chybaZrcadlovy: boolean;
  vysledek: ansistring;
  i: longint;
  
begin
  palindrom := false;
  zrcadlovy := false;
  
  chybaPalindrom := false;
  chybaZrcadlovy := false;
  for i := 1 to length(retezec) do begin
    
    //writeln('Aha ', length(retezec));
    
    if (retezec[i] <> retezec[length(retezec) - i + 1]) then begin
      chybaPalindrom := true;
    end;
    
    //writeln('Aha 2');
     
    if (NOT jsouZnakyOpacne(retezec[i], retezec[length(retezec) - i + 1])) then begin
      chybaZrcadlovy := true;
    end;
    
    if (chybaPalindrom AND chybaZrcadlovy) then begin  //Predcasne ukonceni cyklu, kdyz uz je jasne, ze se jedna pouze o obycejny retezec
      break;
    end;
  end;
  
  //writeln('Aha 3');
  
  palindrom := NOT chybaPalindrom;
  zrcadlovy := NOT chybaZrcadlovy;
  
  vysledek := retezec + ': ';
  
  if ((NOT palindrom) AND (NOT zrcadlovy)) then begin
    vysledek := vysledek + 'retezec';
  end
  else if ((palindrom) AND (NOT zrcadlovy)) then begin
    vysledek := vysledek + 'palindrom';
  end
  else if ((NOT palindrom) AND (zrcadlovy)) then begin
    vysledek := vysledek + 'zrcadlovy retezec';
  end
  else begin
    vysledek := vysledek + 'zrcadlovy palindrom';
  end;
  
  urciTypRetezce := vysledek;
end;

(*
 * Vstupni bod programu
 *)
begin
  //Inicializace pole znaku
  znaky[0] := '1';
  znaky[1] := '2';
  znaky[2] := '3'; 
  znaky[3] := '5';
  znaky[4] := '8';
  znaky[5] := 'A';
  znaky[6] := 'E';
  znaky[7] := 'H';
  znaky[8] := 'I';
  znaky[9] := 'J';
  znaky[10] := 'L';
  znaky[11] := 'M';
  znaky[12] := 'O';
  znaky[13] := 'S';
  znaky[14] := 'T';
  znaky[15] := 'U';
  znaky[16] := 'V';
  znaky[17] := 'W';
  znaky[18] := 'X';
  znaky[19] := 'Y';
  znaky[20] := 'Z';
  
  //Inicializace pole znaku opacnych
  znakyOpacne[0] := '1';
  znakyOpacne[1] := 'S';
  znakyOpacne[2] := 'E';
  znakyOpacne[3] := 'Z';
  znakyOpacne[4] := '8';
  znakyOpacne[5] := 'A';
  znakyOpacne[6] := '3';
  znakyOpacne[7] := 'H';
  znakyOpacne[8] := 'I';
  znakyOpacne[9] := 'L';
  znakyOpacne[10] := 'J';
  znakyOpacne[11] := 'M';
  znakyOpacne[12] := 'O';
  znakyOpacne[13] := '2';
  znakyOpacne[14] := 'T';
  znakyOpacne[15] := 'U';
  znakyOpacne[16] := 'V';
  znakyOpacne[17] := 'W';
  znakyOpacne[18] := 'X';
  znakyOpacne[19] := 'Y';
  znakyOpacne[20] := '5';
  
  readln(pocetRetezcu);
  
  for i := 0 to (pocetRetezcu - 1) do begin
    readln(retezec);
    
    writeln(urciTypRetezce(retezec));
    writeln();
  end;
end.