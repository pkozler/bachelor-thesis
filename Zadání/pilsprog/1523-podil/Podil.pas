program Podil;
const
  DEFAULT_ARRAYLIST_CAPACITY = 1024;
  (* Konstanta pro znamenko + *)
  ZNAMENKO_PLUS = 1;
  (* Konstanta pro znamenko - *)
  ZNAMENKO_MINUS = -1;
  (*  *)
  POCET_DESETINNYCH_MIST_NAVIC = 400000;
  (*  *)
  MAXIMALNI_DELKA_ZBYTKU = 1000;

type 
  TCislice = array of longint;
  TArrayListData = array of TCislice;
  TArrayList = record
    data: TArrayListData;
    size: longint;
    capacity: longint;
  end;
  TVelkeCislo = record
    znamenko: longint;
    cislice: TCislice;
    neniNula: boolean;
  end;
  
var
  pocetRadek: longint;
  radka: ansistring;
  i: longint;

function max(number1: longint; number2: longint): longint;
begin
  if (number1 > number2) then begin
    max := number1;
  end
  else begin
    max := number2;
  end;
end;

(*
 * Initialize an arraylist with default capacity and zero size
 * @param this The arraylist to initialize
 *)
procedure TArrayList_init(var this: TArrayList);
begin
  setLength(this.data, DEFAULT_ARRAYLIST_CAPACITY);
  this.size := 0;
  this.capacity := DEFAULT_ARRAYLIST_CAPACITY;
end;

(*
 * Returns the size of this arraylist
 * @param this the arraylist, whose size should be returned 
 * @return the size of this arraylist
 *)
function TArrayList_size(var this: TArrayList): longint;
begin
  TArrayList_size := this.size;
end;

function TArrayList_isEmpty(var this: TArrayList): boolean;
begin
  TArrayList_isEmpty := (this.size = 0);
end;

procedure TArrayList_clear(var this: TArrayList);
begin
  this.size := 0;
end;

(*
 * Adds a number to the end of the arraylist
 * @param this the arraylist, to which the number shall be added 
 * @param element the element to be added to this arraylist
 *)
procedure TArrayList_add(var this: TArrayList; element: TCislice);
begin
  if (this.size < this.capacity - 1) then begin
    this.data[this.size] := element;
    inc(this.size);
  end
  else begin
    this.capacity := this.capacity * 2;
    setLength(this.data, this.capacity); 
  end;             
end;

function TArrayList_get(var this: TArrayList; index: longint): TCislice;
var
  empty: TCislice;
  
begin
  if ((index >= 0) AND (index < this.size)) then begin
    TArrayList_get := this.data[index];
  end
  else begin
    setLength(empty, 0);
    TArrayList_get := empty;
  end;
end;

(*
 * Vytvori instanci velkeho cisla na zaklada zadaneho retezce obsahujiho velke cislo
 * @param cisloStr velke cislo reprezentovane retezcem
 *)        
procedure TVelkeCislo_init(var this: TVelkeCislo; cisloStr: ansistring);
var
  i: longint;

begin
  this.neniNula := false;
  
  if (cisloStr[1] = '-') then begin
    this.znamenko := ZNAMENKO_MINUS;
    setLength(this.cislice, length(cisloStr) - 1);
    
    for i := 0 to (length(this.cislice) - 1) do begin
      this.cislice[i] := ord(cisloStr[i + 2]) - ord('0');
      
      //write(this.cislice[i]);
      
      if (this.cislice[i] <> 0) then begin
        this.neniNula := true;
      end;
    end;
    //writeln();
  end
  else begin
    this.znamenko := ZNAMENKO_PLUS;
    setLength(this.cislice, length(cisloStr));
    
    for i := 0 to (length(this.cislice) - 1) do begin
      this.cislice[i] := ord(cisloStr[i + 1]) - ord('0');
      
      //write(this.cislice[i]);
      
      if (this.cislice[i] <> 0) then begin
        this.neniNula := true;
      end;
    end;
    //writeln();
  end;
end;

(*
 * Porovna dve sady cislic tvorici cisla a vrati -1, pokud je prvni sada vetsi, 1 pokud je druha sada vetsi, nebo 0, pokud jsou shodne 
 * @param cislice1 sada cislic 1
 * @param posun1 posun v sade cislic 1
 * @param cislice2 sada cislic 2
 * @param delka2 delka sady cislic 2       
 * @return -1, pokud je prvni sada vetsi, 1 pokud je druha sada vetsi, nebo 0, pokud jsou shodne
 *)              
function TVelkeCislo_porovnej(var this: TVelkeCislo; cislice1: TCislice; posun1: longint; cislice2: TCislice; delka2: longint): longint;
var
  i: longint;

begin
  if (posun1 - 1 >= 0) then begin
    if (cislice1[posun1 - 1] > 0) then begin
      TVelkeCislo_porovnej := -1;
      exit;
    end;
  end;

  for i := 0 to (delka2 - 1) do begin
    if (cislice1[i + posun1] <> cislice2[i]) then begin
      break;
    end;
  end;
  if (i = delka2) then begin
    dec(i);
  end;
  
  if (cislice1[i + posun1] > cislice2[i]) then begin
    TVelkeCislo_porovnej := -1;
  end
  else if (cislice1[i + posun1] < cislice2[i]) then begin
    TVelkeCislo_porovnej := 1;
  end
  else begin 
    TVelkeCislo_porovnej := 0;
  end;
end;
  
(*
 *
 * @param zbytek1   
 * @param zbytek2
 * @return   
 *)        
function TVelkeCislo_jsouZbytkyShodne(var this: TVelkeCislo; zbytek1: TCislice; zbytek2: TCislice): boolean;
var
  shodne: boolean;  
  i: longint;

begin
  if (length(zbytek1) <> length(zbytek2)) then begin
    TVelkeCislo_jsouZbytkyShodne := false;
  end
  else begin
    shodne := true;
    for i := 0 to (length(zbytek1) - 1) do begin
      if (zbytek1[i] <> zbytek2[i]) then begin
        shodne := false;
        break;
      end;
    end;
    
    TVelkeCislo_jsouZbytkyShodne := shodne;
  end;
end;

(*
 * Vydeli toto velke cislo delitelem (realne, ne celociselne). Predpoklada se, ze obe cisla jsou cela (bez desetinne casti)
 * Funguje to pomoci odcitani - odecitam delitelele od delenece a pricitam 1 do vysledku, dokud neni delitel mensi nez delenec
 * Potom posunu delence smerem vlevo, abych ziskal cislo vetsi nez delitel a o stejny pocet mist posunu vysledek
 * Opakuji, dokud neni cislo cele vydelene nebo dokud zbyva zbytek
 * Zbytek muze zbyvat porad, je treba detekovat periodicky rozvoj - zapamatuji si vsechny zbytky a pri kazdem dalsim zbytku hledam, jetli uz jsem ho nemel. Kdyz jo, je perioda. Navic, abz se urcil presne zacatek, provedu vypocet po dobu dvou period, tim zjistim presne delku periody a porovnanim cislic ve vysledku i presny zacatek periody.
 * Viz http://www.builder.cz/cz/forum/tema-1283658-deleni-velkych-cisel-po-cifre/              
 * @param delitel delitel, kterym se ma toto velke cislo vydelit  
 * @return podil tohoto cisla a delitele (vysledek deleni) 
 *)        
function TVelkeCislo_vydel(var this: TVelkeCislo; var delitel: TVelkeCislo): ansistring;
var
  vysledek: TCislice;
  delenec: TCislice;
  i, j: longint;
  zbytky: TArrayList;
  pocetZbytku: longint;
  zbytek: TCislice;
  
  posunDelenec: longint;
  poziceDelenec: longint;
  poziceDelitel: longint;
  cisliceOdcitani: longint;
  cislicePrenosu: longint;
  indexCisliceVysledku: longint;
  porovnani: longint;
  
  indexZacatkuPeriody: longint;
  indexDesetinneTecky: longint;
  perioda: boolean;
  delkaPeriody: longint;
  uzJsemTuByl: boolean;
  pocatecniPosunDelenec: longint;
  nulovyDelenec: boolean;
  shodnyZbytekIndex: longint;
  vysledekStr: ansistring;
  puvodniIndexDesetinneTecky: longint;
  tecka: longint;
  nalezeno: boolean;
  
begin  
  if (NOT this.neniNula) then begin  //Delenec je nulovy
    TVelkeCislo_vydel := '0';
    exit;
  end;

  setLength(vysledek, length(this.cislice) + POCET_DESETINNYCH_MIST_NAVIC);
  setLength(delenec, length(this.cislice) + POCET_DESETINNYCH_MIST_NAVIC);
  TArrayList_init(zbytky);
  pocetZbytku := 0;
  
  for i := 0 to (length(this.cislice) - 1) do begin
    delenec[i] := this.cislice[i];
    vysledek[i] := 0;
  end; 
  
  for i := length(this.cislice) to (length(delenec) - 1) do begin
    delenec[i] := 0;
    vysledek[i] := 0;
  end;
  
  posunDelenec := 0;
  poziceDelenec := 0;
  poziceDelitel := 0;
  cisliceOdcitani := 0;
  cislicePrenosu := 0;
  indexCisliceVysledku := 0;
  porovnani := 0;
  
  indexZacatkuPeriody := 0;
  indexDesetinneTecky := 0;
  perioda := false;
  delkaPeriody := -1;
  uzJsemTuByl := false;
     
  //Transformace delence (posun vravo), aby byl pri prvnim deleni vetsi nez delitel. Pokud vyjde posun zaporny, znamena to, ze delenec je vetsi nez delitel a pak vyuzijeme jen cast delence   
  pocatecniPosunDelenec := length(delitel.cislice) - length(this.cislice);
  indexDesetinneTecky := -pocatecniPosunDelenec;
  if (TVelkeCislo_porovnej(this, delenec, 0, delitel.cislice, length(delitel.cislice)) = 1) then begin  //Delitel je vetsi kdyz vezmu stejny pocet cislic delence - uprava o jedno misto
    //writeln('Jsem tu');
    inc(pocatecniPosunDelenec);
    inc(posunDelenec);
    dec(indexDesetinneTecky);
  end;
   
  while (true) do begin
    porovnani := TVelkeCislo_porovnej(this, delenec, posunDelenec, delitel.cislice, length(delitel.cislice));
    while (porovnani <= 0) do begin //Dokud je delenec vetsi nebo stejny nez delitel, odecitej delitele od delence
      cislicePrenosu := 0; 
      for i := (length(delitel.cislice) - 1) downto 0 do begin  //Jedno odecteni delitele od delence
        cisliceOdcitani := delenec[i + posunDelenec] - (delitel.cislice[i] + cislicePrenosu);
        
        if (cisliceOdcitani < 0) then begin
          inc(cisliceOdcitani, 10);
          cislicePrenosu := 1;
        end 
        else begin
          cislicePrenosu := 0;
        end;
        
        delenec[i + posunDelenec] := cisliceOdcitani;
      end;
      if (cislicePrenosu > 0) then begin
        dec(delenec[posunDelenec - 1], cislicePrenosu);
      end;
      
      inc(vysledek[indexCisliceVysledku]);
      
      porovnani := TVelkeCislo_porovnej(this, delenec, posunDelenec, delitel.cislice, length(delitel.cislice));
    end;
    
    //writeln('Vysledek ', vysledek[indexCisliceVysledku]);
    
    nulovyDelenec := true;
    //writeln('No ', max(length(delitel.cislice), length(this.cislice)), ' posunDelenec ', posunDelenec);
    {write('delenec ');
    for i := 0 to (max(length(delitel.cislice), length(this.cislice)) - 1) do begin
      write(delenec[posunDelenec + i]);
    end;}
    
    for i := 0 to (max(length(delitel.cislice), length(this.cislice)) - 1) do begin
      if (delenec[posunDelenec + i] <> 0) then begin
        nulovyDelenec := false;
        inc(posunDelenec, i);
        inc(indexCisliceVysledku, i);
        break;
      end;
    end;
    
    //writeln();
    //writeln('Nene: ', indexCisliceVysledku);
    //writeln('Nulovy delenec ', nulovyDelenec);
    
    if (nulovyDelenec) then begin //Nezbyl zadny zbytek
      break;
    end
    else begin  //Nejaky zbytek zbyl, ulozim si ho do pole zbytku
      setLength(zbytek, max(length(delitel.cislice), length(this.cislice)) - i);

      for j := 0 to (length(delitel.cislice) - i - 1) do begin
        zbytek[j] := delenec[posunDelenec + j];
      end;
      
      if (posunDelenec >= length(this.cislice) - length(delitel.cislice)) then begin
      
        shodnyZbytekIndex := -1;            
        for j := 0 to (TArrayList_size(zbytky) - 1) do begin //Prohledani zbytku, zda uz novy zbytek neni obsazen
          if (TVelkeCislo_jsouZbytkyShodne(this, zbytek, TArrayList_get(zbytky, j))) then begin
            if (NOT uzJsemTuByl) then begin
              TArrayList_clear(zbytky);
              pocetZbytku := 0;
              uzJsemTuByl := true;
              delkaPeriody := posunDelenec;
            end
            else begin
              delkaPeriody := posunDelenec - delkaPeriody;
              shodnyZbytekIndex := j;  
              break;
            end;
          end;
        end;
        if (shodnyZbytekIndex < 0) then begin
          TArrayList_add(zbytky, zbytek);
          inc(pocetZbytku);
        end
        else begin //Novy zbytek uz je obsazen - detekovana perioda
          perioda := true;
          break;
        end;
      end;
    end;
    
    if (TVelkeCislo_porovnej(this, delenec, posunDelenec, delitel.cislice, length(delitel.cislice)) = 1) then begin
      inc(posunDelenec);
      inc(indexCisliceVysledku);
    end;
  end;
  
  vysledekStr := ''; 
  if (this.znamenko <> delitel.znamenko) then begin
    vysledekStr := '-';
  end;
  
  puvodniIndexDesetinneTecky := indexDesetinneTecky;
  
  if (indexDesetinneTecky < 0) then begin
    vysledekStr := vysledekStr + '0.';
    
    inc(indexDesetinneTecky);
    while (indexDesetinneTecky < 0) do begin
      vysledekStr := vysledekStr + '0';
      inc(indexDesetinneTecky);
    end;
    indexDesetinneTecky := -1; //Abych uz se ji nezabyval v nasledujicim cyklu
  end
  else if (indexDesetinneTecky = 0) then begin
    if ((length(delitel.cislice) > length(this.cislice)) OR ((length(delitel.cislice) = length(this.cislice)) AND (TVelkeCislo_porovnej(this, this.cislice, 0, delitel.cislice, length(delitel.cislice)) = 1))) then begin  //Delitel je vetsi nez delenec
      vysledekStr := vysledekStr + '0.';
    end
    else begin
      inc(indexDesetinneTecky);
    end;
  end;
  
  if (puvodniIndexDesetinneTecky > 0) then begin
    inc(indexDesetinneTecky);
  end;
  
  //write('Aha ', indexCisliceVysledku, ': ');
  for i := 0 to indexCisliceVysledku do begin
    //write(vysledek[i]);
    if (indexDesetinneTecky > 0) then begin
      if (i = indexDesetinneTecky) then begin
        vysledekStr := vysledekStr + '.';
      end;
    end;
    
    vysledekStr := vysledekStr + chr(vysledek[i] + ord('0'));
  end;
  //writeln();
  
  if (delkaPeriody >= 0) then begin
    tecka := pos('.', vysledekStr);
    
    for i := 0 to (length(vysledekStr) - tecka - 1) do begin
      nalezeno := true;
      
      for j := 0 to (delkaPeriody - 1) do begin
        if (((j + tecka + 1 + delkaPeriody + i) > length(vysledekStr)) OR (vysledekStr[j + tecka + 1 + i] <> vysledekStr[j + tecka + 1 + delkaPeriody + i])) then begin
          nalezeno := false;
          break;
        end;
      end;
      
      if (nalezeno) then begin
        indexZacatkuPeriody := (i + tecka);
        break;
      end;
    end;
    
    vysledekStr := copy(vysledekStr, 1, indexZacatkuPeriody) + '(' + copy(vysledekStr, indexZacatkuPeriody + 1, delkaPeriody) + ')'; 
  end;
  
  TVelkeCislo_vydel := vysledekStr;
end;

(*
 * Zpracuje jednu nactenou radku - rozdeli ji podle dvojtecky na delenec a delitel, provede deleni s vyuzitim velkych cisel a vypise vysledek na samostatnou radku.
 *)        
procedure zpracujRadku(radka: ansistring);
var
  indexDvojtecky: longint;
  delenec: TVelkeCislo;
  delitel: TVelkeCislo;
begin
  indexDvojtecky := pos(' : ', radka);
  TVelkeCislo_init(delenec, copy(radka, 1, indexDvojtecky - 1));
  TVelkeCislo_init(delitel, copy(radka, indexDvojtecky + 3, length(radka) - indexDvojtecky - 2));
       
  writeln(TVelkeCislo_vydel(delenec, delitel));
end;
  
begin
  readln(pocetRadek);
  
  for i := 0 to (pocetRadek - 1) do begin
    readln(radka);
    zpracujRadku(radka);
  end;
end.