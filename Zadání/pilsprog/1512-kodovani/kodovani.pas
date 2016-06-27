program Kodovani;

const
  POCET_ZNAKU = 59;

type
  TZnaky = array[0..POCET_ZNAKU - 1] of char;
  TKody = array[0..POCET_ZNAKU - 1] of longint;
  TPoleZnaku = array of char;

var
  znaky: TZnaky;
  kody: TKody;
  pocetRadek: longint;
  radka: ansistring;
  i: longint;

(*
 * Najde a vrati index znaku v poli povolenych znaku pomoci binarniho vyhledavani
 * @param znak znak, ktery ma byt nalezen v poli povolenych znaku 
 * @return index nalezeneho znaku v poli povolenych znaku, nebo -1, pokud znak neni nalezen 
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
    //writeln('D: ', dolniMez, ', H: ', horniMez);
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
 * Najde a vrati index ASCII kodu v poli kodu pomoci binaarniho vyhledavani
 * @param kod ASCII kod, ktery ma byt nalezen v poli kodu
 * @return index nalezeneho znaku v poli kodu, nebo -1, pokud kod neni nalezen     
 *)        
function najdiIndexKodu(kod: longint): longint;
var
  dolniMez: longint;
  horniMez: longint;
  stred: longint;
  
begin
  dolniMez := 0;
  horniMez := length(kody) - 1;
  stred := 0;
  
  while (dolniMez <= horniMez) do begin
    stred := (dolniMez + horniMez) div 2;
    
    if (kody[stred] < kod) then begin
      dolniMez := stred + 1;
    end 
    else if (kody[stred] > kod) then begin
      horniMez := stred - 1;
    end                       
    else begin
      najdiIndexKodu := stred;
      exit;
    end;
  end;
  
  najdiIndexKodu := -1;
end;

(*
 * Zakoduje zadanou zpravu a vrati ji
 * @param zprava zprava, ktera se ma zakodovat
 * @return zakodovana zprava  
 *)        
procedure zakoduj(zprava: ansistring);
var
  index: longint;
  kod: longint;
  kodStr: ansistring;
  i, j: longint; 

begin
  index := -1;
  kod := 0;
    
  for i := length(zprava) downto 1 do begin
    //writeln(i);
    index := najdiIndexZnaku(zprava[i]);
    
    if (index >= 0) then begin
      kod := kody[index];
      str(kod, kodStr);
            
      for j := length(kodStr) downto 1 do begin
        write(kodStr[j]);
      end;
    end
    else begin
      write('X');  //Znak nebyl nalezen - nejedna se o platny znak, vypisu do vystupu X (tj. mezi cisla) jako indikaci chyby
    end;
  end;
  writeln();
end;

(*
 * Dekoduje zadanou zakodovanou zpravu a vrati puvodni (dekodovanou) zpravu
 * @param kodovanaZprava zakodovana zprava, ktera se ma dekodovat
 * @return puvodni (dekodovana) zprava   
 *)        
procedure dekoduj(kodovanaZprava: ansistring);
var
  zpravaObracene: TPoleZnaku;
  pocetZnaku: longint;
  znak1: char;
  znak2: char;
  znak3: char;
  kod: longint;
  indexKodovaneZpravy: longint;
  indexKodu: longint;
  i: longint;

begin
  setLength(zpravaObracene, length(kodovanaZprava)); //Zprava bude kratsi nez kodovana, takze velikost bohate staci  
  pocetZnaku := 0;
  znak1 := '0';
  znak2 := '0';
  znak3 := '0';
  kod := 0;
  indexKodovaneZpravy := 1;
  indexKodu := 0;
  
  while (indexKodovaneZpravy + 1 <= length(kodovanaZprava)) do begin
    znak1 := kodovanaZprava[indexKodovaneZpravy];
    znak2 := kodovanaZprava[indexKodovaneZpravy + 1];
    kod := 10 * (ord(znak2) - ord('0')) + (ord(znak1) - ord('0'));
    indexKodu := najdiIndexKodu(kod);
    
    if (indexKodu >= 0) then begin //Kod nalezen, dva znaky tedy byly cely kod
      zpravaObracene[pocetZnaku] := znaky[indexKodu];
      indexKodovaneZpravy := indexKodovaneZpravy + 2;
    end
    else begin //Kod nenalezen, pridame treti znak
      if (indexKodovaneZpravy + 2 <= length(kodovanaZprava)) then begin // Treti znak je dostupny
        znak3 := kodovanaZprava[indexKodovaneZpravy + 2];
        kod := 100 * (ord(znak3) - ord('0')) + 10 * (ord(znak2) - ord('0')) + (ord(znak1) - ord('0'));
        indexKodu := najdiIndexKodu(kod);
        
        if (indexKodu >= 0) then begin
          zpravaObracene[pocetZnaku] := znaky[indexKodu];
        end
        else begin //Kod nenalezen ani se tretim znakem - chyba
          zpravaObracene[pocetZnaku] := '0';
        end;
      end
      else begin //Treti znak neni dostupny - chyba
        zpravaObracene[pocetZnaku] := '0';
      end;
      indexKodovaneZpravy := indexKodovaneZpravy + 3;
    end;
    
    inc(pocetZnaku);
  end;
  
  for i := (pocetZnaku - 1) downto 0 do begin
    write(zpravaObracene[i]);
  end;
  writeln();  
end;

(*
 * Returns <code>true</code>, when the specified character is a digit or <code>false</code> otherwise
 * @param character a character 
 * @return <code>true</code>, when the specified character is a digit or <code>false</code> otherwise 
 *)
function isDigit(character: char): boolean;
begin
 isDigit := ((character >= '0') AND (character <= '9'));
end;

(*
 * Zpracuje jednu radku. Podle prvniho znaku na radce bud zpravu zakoduje nebo dekoduje a vysledek vypise na standarni vystup.
 *)     
procedure zpracujRadku(radka: ansistring);
begin
  if (length(radka) > 0) then begin
    if (isDigit(radka[1])) then begin
      dekoduj(radka);
    end
    else begin
      zakoduj(radka);
    end
  end
  else begin
    writeln();
  end;
end;

(*
 * Vstupni bod programu
 *)  
begin
  //Inicializace kodu
  kody[0] := 32;
  kody[1] := 33;
  kody[2] := 44;
  kody[3] := 46;
  kody[4] := 58;
  kody[5] := 59;
  kody[6] := 63;
  kody[7] := 65;
  kody[8] := 66;
  kody[9] := 67;
  kody[10] := 68;
  kody[11] := 69;
  kody[12] := 70;
  kody[13] := 71;
  kody[14] := 72;
  kody[15] := 73;
  kody[16] := 74;
  kody[17] := 75;
  kody[18] := 76;
  kody[19] := 77;
  kody[20] := 78;
  kody[21] := 79;
  kody[22] := 80;
  kody[23] := 81;
  kody[24] := 82;
  kody[25] := 83;
  kody[26] := 84;
  kody[27] := 85;
  kody[28] := 86;
  kody[29] := 87;
  kody[30] := 88;
  kody[31] := 89;
  kody[32] := 90;
  kody[33] := 97;
  kody[34] := 98;
  kody[35] := 99;
  kody[36] := 100;
  kody[37] := 101;
  kody[38] := 102;
  kody[39] := 103;
  kody[40] := 104;
  kody[41] := 105;
  kody[42] := 106;
  kody[43] := 107;
  kody[44] := 108;
  kody[45] := 109;
  kody[46] := 110;
  kody[47] := 111;
  kody[48] := 112;
  kody[49] := 113;
  kody[50] := 114;
  kody[51] := 115;
  kody[52] := 116; 
  kody[53] := 117;
  kody[54] := 118;
  kody[55] := 119;
  kody[56] := 120;
  kody[57] := 121;
  kody[58] := 122;
  
  //Inicializace znaku
  znaky[0] := ' ';
  znaky[1] := '!';
  znaky[2] := ',';
  znaky[3] := '.';
  znaky[4] := ':';
  znaky[5] := ';';
  znaky[6] := '?';
  znaky[7] := 'A';
  znaky[8] := 'B';
  znaky[9] := 'C';
  znaky[10] := 'D';
  znaky[11] := 'E';
  znaky[12] := 'F';
  znaky[13] := 'G';
  znaky[14] := 'H';
  znaky[15] := 'I';
  znaky[16] := 'J';
  znaky[17] := 'K';
  znaky[18] := 'L';
  znaky[19] := 'M';
  znaky[20] := 'N';
  znaky[21] := 'O';
  znaky[22] := 'P';
  znaky[23] := 'Q';
  znaky[24] := 'R';
  znaky[25] := 'S';
  znaky[26] := 'T';
  znaky[27] := 'U';
  znaky[28] := 'V';
  znaky[29] := 'W';
  znaky[30] := 'X';
  znaky[31] := 'Y';
  znaky[32] := 'Z';
  znaky[33] := 'a';
  znaky[34] := 'b';
  znaky[35] := 'c';
  znaky[36] := 'd';
  znaky[37] := 'e';
  znaky[38] := 'f';
  znaky[39] := 'g';
  znaky[40] := 'h';
  znaky[41] := 'i';
  znaky[42] := 'j';
  znaky[43] := 'k';
  znaky[44] := 'l';
  znaky[45] := 'm';
  znaky[46] := 'n';
  znaky[47] := 'o';
  znaky[48] := 'p';
  znaky[49] := 'q';
  znaky[50] := 'r';
  znaky[51] := 's';
  znaky[52] := 't';
  znaky[53] := 'u';
  znaky[54] := 'v';
  znaky[55] := 'w';
  znaky[56] := 'x';
  znaky[57] := 'y';
  znaky[58] := 'z';
  
  readln(pocetRadek);
  
  //writeln('Pocet radek: ', pocetRadek);
  
  for i := 0 to (pocetRadek - 1) do begin
    //writeln('Aha', i);
    readln(radka);
    zpracujRadku(radka);
  end;
end.