program NejdelsiSpolecnaSekvence;

type
  TTabulkaDelek = array of array of longint;

var
  pocetTestovacichPripadu: longint;
  retezec1: ansistring;
  retezec2: ansistring;
  i: longint;

(*
 * Returns the higher value of two specified integer numbers
 * @param number1 first number
 * @param number2 second number
 * @return the higher number of two specified integer number   
 *)
function max(number1: longint; number2: longint): longint;
begin
  if (number1 >= number2) then begin
    max := number1;
  end
  else begin
    max := number2;
  end;
end;

(*
 * Najde a vrati delku nejdelsi spolecne sekvence zadanych retezcu s vyuzitim dynamickeho programovani
 * @param retezec1 prvni retezec
 * @param retezec2 druhy retezec
 * @return delka nejdelsi spolecne sekvence zadanych retezcu
 *)              
function najdiDelkuNejdelsiSpolecneSekvence(retezec1: ansistring; retezec2: ansistring): longint;
var
  tabulkaDelek: TTabulkaDelek;
  i, j: longint;
  
begin
  if ((length(retezec1) = 0) OR (length(retezec2) = 0)) then begin 
    najdiDelkuNejdelsiSpolecneSekvence := 0;
    exit;
  end
  else begin
    setLength(tabulkaDelek, length(retezec1) + 1, length(retezec2) + 1);
    
    //Vynulovani nulte radky
    for i := 0 to (length(tabulkaDelek[0]) - 1) do begin
      tabulkaDelek[0][i] := 0;
    end;
    //Vynulovani nulteho sloupce
    for i := 0 to (length(tabulkaDelek) - 1) do begin
      tabulkaDelek[i][0] := 0;
    end;
    
    //Vyplneni tabulky po postupne po radcich - pokud jsou si znaky reprezentujici radek a sloupec rovny, vezme se cislo o radek a sloupec vys a pricte se k nemu jednicka
    for i := 0 to (length(retezec1) - 1) do begin
      for j := 0 to (length(retezec2) - 1) do begin
        if (retezec1[i + 1] = retezec2[j + 1]) then begin
          tabulkaDelek[i + 1][j + 1] := tabulkaDelek[i][j] + 1;
        end
        else begin
          tabulkaDelek[i + 1][j + 1] := max(tabulkaDelek[i][j + 1], tabulkaDelek[i + 1][j]);
        end;
      end;
    end;
    
    //Vypis vyplnene tabulky
    {for i := 0 to  (length(tabulkaDelek) - 1) do begin
      for j := 0; j < (length(tabulkaDelek[i]) - 1) do begin
        write(' ' + tabulkaDelek[i][j]);
      end;
      witeln();
    end}
    
    //Vraceni hodnoty z praveho dolniho rohu tabulky (vysledek)
    najdiDelkuNejdelsiSpolecneSekvence := tabulkaDelek[length(retezec1)][length(retezec2)];
  end;
end;

(*
 * Vstupni bod programu
 *)  
begin
  readln(pocetTestovacichPripadu);
    
  for i := 0 to (pocetTestovacichPripadu - 1) do begin
    readln(retezec1);
    readln(retezec2);
    writeln(najdiDelkuNejdelsiSpolecneSekvence(retezec1, retezec2));
  end;
end.