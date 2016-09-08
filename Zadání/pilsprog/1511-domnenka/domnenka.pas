program Domnenka;

const
  HORNI_MEZ = 1000000;

type
  TJePrvocislo = array[0..HORNI_MEZ - 1] of boolean;

var
  jePrvocislo: TJePrvocislo;
  vstupniCislo: longint;

(*
 * Naplni pole indikace prvocisel s vyuzitim Eratosthenova sita   
 *)     
procedure naplnJePrvocislo();
var
  i, j: longint;

begin
  for i := 0 to (length(jePrvocislo) - 1) do begin
    jePrvocislo[i] := true; //Predpokladam, ze vse jsou prvocisla
  end;
  jePrvocislo[0] := false; //0 neni prvocislo 
  jePrvocislo[1] := false; //1 neni prvocislo
      
  for i := 2 to round(sqrt(length(jePrvocislo))) do begin
    if (jePrvocislo[i]) then begin //Pokud najdu prvocislo, vyradim vsechny jeho nasobky
      j := 2 * i;
      while (j < length(jePrvocislo)) do begin
        jePrvocislo[j] := false;
        j := j + i;
      end;
    end;
  end;
end;

(*
 * Nalezne a vypise na standarni vystup rozklad zadaneho cisla na soucet prvocisel. Pokud rozklad neni nalezen, vypise "Neplati!"
 * @param vstupniCislo cislo, pro ktere se hleda rozklad na prvocisla
 *)        
procedure najdiAVypisRozkladCisla(vstupniCislo: longint);
var
  cisloA: longint;
  cisloB: longint;
  nalezeno: boolean;

begin  
  cisloA := 1;
  cisloB := vstupniCislo - 1;
  nalezeno := false;
  
  while (cisloA < cisloB) do begin //Projdu vsechny mozne scitance, dokud nenaleznu dva prvociselne
    if (jePrvocislo[cisloA] AND jePrvocislo[cisloB]) then begin
      nalezeno := true;
      break;
    end;
    
    inc(cisloA);
    dec(cisloB);
  end;
  
  if (nalezeno) then begin
    writeln(vstupniCislo, ' = ', cisloA, ' + ', cisloB);
  end
  else begin
    writeln('Neplati!');
  end;
end;

begin
  naplnJePrvocislo();
    
  readln(vstupniCislo);
  while (vstupniCislo <> 0) do begin //Dokud neni cislo 0 (ukoncovaci hodnota)
    najdiAVypisRozkladCisla(vstupniCislo);
    readln(vstupniCislo);
  end;
end.