program Trezor;

const
  (* Barva vrcholu pro DFS - bila *)
  BILA = -1;
  (* Barva vrcholu pro DFS - seda *)
  SEDA = -2;
  (* Barva vrcholu pro DFS - cerna *)
  CERNA = -3;
  (* Delka klice k trezoru (pocet cislic) *)
  DELKA_KLICE = 4;
  (* Maximalni mozny pocet otoceni *)
  MAXIMALNI_POCET_OTOCENI = 10000;
  
type
  TStringTokenizer = record
    stringToSplit: ansistring;
    splitCharacter: char;
    remainingString: ansistring;
  end;
  THrana = record
    ohodnoceni: longint;
    index1: longint;
    index2: longint;
  end;
  TKlice = array of ansistring;
  TPrechodyMeziKlici = array of array of longint;
  THrany = array of THrana;
  TJedenTrezor = record
    (* Vsechny klice k trezoru *)
    klice: TKlice;
    (* Prechody mezi klici - matice (neorientovanych) hran grafu, na hlavni diagonale je ulozena barva vrcholu, mimo hlavni diagonalu hodnata BILA znamena, ze tam neni hrana *)
    prechodyMeziKlici: TPrechodyMeziKlici;
    (* Pocet vsech klicu *)
    pocetKlicu: longint;
    (* Pocet vsech neorientovanych hran (prechodu mezi klici) *)
    pocetHran: longint;
    (* Pole vsech hran (prechodu mezi klici) *)
    hrany: THrany;
    (* Promenna, do ktere DFS zaznamena, ze naslo cestu mezi dvema vrcholy *)
    cestaExistuje: boolean;
  end;

var
  pocetTrezoru: longint;
  radka: ansistring;
  jedenTrezor: TJedenTrezor;
  i: longint;

(*
 *
 * @param this
 * @param stringToSplit  
 * @param splitCharacter 
 *)
procedure TStringTokenizer_init(var this: TStringTokenizer; stringToSplit: ansistring; splitCharacter: char);
begin
  this.stringToSplit := stringToSplit;
  this.remainingString := stringToSplit;
  this.splitCharacter := splitCharacter;
end;

(*
 * 
 * @param this
 * @return
 *)
function TStringTokenizer_hasNextToken(var this: TStringTokenizer): boolean;
begin
  TStringTokenizer_hasNextToken := (length(this.remainingString) = 0);
end;

(*
 *
 * @param this
 * @return 
 *)
function TStringTokenizer_nextToken(var this: TStringTokenizer): ansistring;
var
  nextToken: ansistring;
  splitCharacterIndex: integer;
begin
  splitCharacterIndex := pos(this.splitCharacter, this.remainingString);
  //writeln('Nalezeno: ', splitCharacterIndex);
  if (splitCharacterIndex > 0) then begin
    nextToken := copy(this.remainingString, 1, splitCharacterIndex - 1);
    if (splitCharacterIndex < length(this.remainingString)) then begin
      this.remainingString := copy(this.remainingString, splitCharacterIndex + 1, length(this.remainingString) - splitCharacterIndex);  
    end
    else begin
      this.remainingString :='';
    end;
    
    TStringTokenizer_nextToken := nextToken;
  end
  else if (length(this.remainingString) > 0) then begin
    nextToken := this.remainingString;
    this.remainingString := '';
    TStringTokenizer_nextToken := nextToken;
  end                           
  else begin            
    TStringTokenizer_nextToken := '';                     
  end;
end;

(*
 * 
 * @param this
 * @return 
 *)
function TStringTokenizer_countTokens(var this: TStringTokenizer): longint;
var
  splitCharacterCount: longint;
  i: longint;
begin
  splitCharacterCount := 0;
  for i := 1 to length(this.stringToSplit) do begin
    if (this.stringToSplit[i] = this.splitCharacter) then begin
      inc(splitCharacterCount);
    end;
  end;
  
  TStringTokenizer_countTokens := splitCharacterCount + 1;
end;

(*
 * Vytvori novou instanci hrany
 * @param ohodnoceni ohodnoceni hrany
 * @param index1 index prvniho vrcholu
 * @param index2 index druheho vrcholu  
 *)           
procedure THrana_init(var this: THrana; ohodnoceni: longint; index1: longint; index2: longint);
begin  
  this.ohodnoceni := ohodnoceni;
  this.index1 := index1;
  this.index2 := index2;
end;

function THrana_compareTo(var this: THrana; h: THrana): longint;
begin
  if (this.ohodnoceni < h.ohodnoceni) then begin
    THrana_compareTo := -1;
  end
  else if (this.ohodnoceni > h.ohodnoceni) then begin
    THrana_compareTo := 1;
  end
  else begin
    THrana_compareTo := 0;
  end;
end;

(*
 * Vytvori novou instanci trezoru ze zadaneho retezce klicu 
 * @param trezorStr retezec obsahujici vsechny klice (s poctem klicu jako prvni cislo)
 *)        
procedure TJedenTrezor_init(var this: TJedenTrezor; trezorStr: ansistring);
var
  st: TStringTokenizer;
  i: longint;
  pomocna: ansistring;
begin
  TStringTokenizer_init(st, trezorStr, ' ');
  this.pocetKlicu := TStringTokenizer_countTokens(st) - 1;
  
  setLength(this.klice, this.pocetKlicu);
  pomocna := TStringTokenizer_nextToken(st); //Zahozeni prvniho tokenu, obsahuje pocet klicu, ktery uz jsme si sami spocitali
  for i := 0 to (this.pocetKlicu - 1) do begin
    this.klice[i] := TStringTokenizer_nextToken(st);
  end; 
end;

(*
 * Urci a vrati nejmensi mozny pocet otoceni, kterym se z prvniho klice stane druhy klic
 * @param klic1 prvni klic                                                                
 * @param klic2 druhy klic
 * @return nejmensi mozny pocet otoceni, kterym se z prvniho klice stane druhy klic   
 *)           
function TJedenTrezor_urciNejmensiPocetOtoceniMeziKlici(var this: TJedenTrezor;klic1: ansistring; klic2: ansistring): longint;
var
  celkovyPocetOtoceni: longint;
  pocetOtoceniCislice: longint;
  i: longint;

begin
  celkovyPocetOtoceni := 0;
  pocetOtoceniCislice := 0;
  
  for i := 1 to DELKA_KLICE do begin
    pocetOtoceniCislice := abs((ord(klic1[i]) - ord('0')) - (ord(klic2[i]) - ord('0')));
    
    if (pocetOtoceniCislice > 5) then begin
      pocetOtoceniCislice := 10 - pocetOtoceniCislice;
    end;
    
    celkovyPocetOtoceni := celkovyPocetOtoceni + pocetOtoceniCislice;
  end;
  
  TJedenTrezor_urciNejmensiPocetOtoceniMeziKlici := celkovyPocetOtoceni;
end;

(*
 * Naplni prechody mezi klici, tj. naplni graf klicu ohodnocenymi hranami prechodu mezi nimy (kazdy vrchol je propojen s kazdym)
 *)     
procedure TJedenTrezor_naplnPrechodyMeziKlici(var this: TJedenTrezor);
var
  indexHrany: longint;
  i, j: longint;

begin
  setLength(this.prechodyMeziKlici, this.pocetKlicu, this.pocetKlicu);
  this.pocetHran := ((this.pocetKlicu - 1) * this.pocetKlicu) div 2;
  setLength(this.hrany, this.pocetHran);
  
  indexHrany := 0;
  for i := 0 to (length(this.prechodyMeziKlici) - 1) do begin
    this.prechodyMeziKlici[i, i] := BILA;
          
    for j := i + 1 to (length(this.prechodyMeziKlici[i]) - 1) do begin
      this.prechodyMeziKlici[i, j] := TJedenTrezor_urciNejmensiPocetOtoceniMeziKlici(this, this.klice[i], this.klice[j]);
      this.prechodyMeziKlici[j, i] := this.prechodyMeziKlici[i, j];
      THrana_init(this.hrany[indexHrany], this.prechodyMeziKlici[i, j], i, j);
      inc(indexHrany);
    end;
  end;
end;


procedure TJedenTrezor_opravVrchol(var this: TJedenTrezor; spodek: longint; vrchniIndex: longint; razeni: longint);  
var
  tmp: THrana;
  naslednik: longint;

begin  
  tmp := this.hrany[vrchniIndex]; 
  naslednik := vrchniIndex * 2 + 1; 
  
  if ((naslednik < spodek) AND (THrana_compareTo(this.hrany[naslednik], this.hrany[naslednik + 1]) = razeni)) then begin 
    naslednik := naslednik + 1; 
  end;
   
  while ((naslednik <= spodek) AND (THrana_compareTo(tmp, this.hrany[naslednik]) = razeni)) do begin 
    this.hrany[vrchniIndex] := this.hrany[naslednik]; 
    vrchniIndex := naslednik; 
    naslednik := naslednik * 2 + 1; 
    
    if ((naslednik < spodek) AND (THrana_compareTo(this.hrany[naslednik], this.hrany[naslednik + 1]) = razeni)) then begin 
      naslednik := naslednik + 1; 
    end; 
  end; 
  
  this.hrany[vrchniIndex] := tmp; 
end; 
  
procedure TJedenTrezor_prohod(var this: TJedenTrezor; leva: longint; prava: longint);
var
  tmp: THrana;
  
begin 
  tmp := this.hrany[prava];     
  this.hrany[prava] := this.hrany[leva]; 
  this.hrany[leva] := tmp; 
end;

procedure TJedenTrezor_seradHrany(var this: TJedenTrezor; sestupne: boolean);
var
  i: longint;
  razeni: integer;
  
begin
  if (sestupne) then begin
    razeni := 1;
  end
  else begin
    razeni := -1;
  end;
   
  for i := (length(this.hrany) DIV 2 - 1) downto 0 do begin 
    TJedenTrezor_opravVrchol(this, length(this.hrany) - 1, i, razeni); 
  end; 

  for i := (length(this.hrany) - 1) downto 1 do begin 
    TJedenTrezor_prohod(this, 0, i); 
    TJedenTrezor_opravVrchol(this, i - 1, 0, razeni); 
  end; 
end;

(*
 * Provede prohledani do hloubky z prvniho do druheho vrcholu. Skocni, kdyz se dostane do druheho vrcholu, nebo kdyz projde vsechny vrcholy. Vrati pocet nasvtivenych vrcholu
 * @param vrchol1 prvni vrchol
 * @param vrchol2 druhy vrchol
 * @return pocet nasvtivenych vrcholu      
 *)        
function TJedenTrezor_dfs(var this: TJedenTrezor; vrchol1: longint; vrchol2: longint): longint;
var
  pocetNavstivenychVrcholu: longint;
  i: longint;
  
begin  
  if (this.cestaExistuje) then begin
    TJedenTrezor_dfs := 1;
  end;
  
  this.prechodyMeziKlici[vrchol1, vrchol1] := SEDA;
  pocetNavstivenychVrcholu := 1;
  
  
  if (vrchol1 = vrchol2) then begin
    this.cestaExistuje := true;
    TJedenTrezor_dfs := pocetNavstivenychVrcholu; 
  end;
  
  for i := 0 to (length(this.prechodyMeziKlici) - 1) do begin
    if ((this.prechodyMeziKlici[vrchol1, i] > BILA) AND (this.prechodyMeziKlici[i, i] = BILA)) then begin
      pocetNavstivenychVrcholu := pocetNavstivenychVrcholu + TJedenTrezor_dfs(this, i, vrchol2);
    end;
  end;
  this.prechodyMeziKlici[vrchol1, vrchol1] := CERNA;
  
  TJedenTrezor_dfs := pocetNavstivenychVrcholu;
end;

(*
 * Urci, zda existuje cesta mezi prvnim a druhym vrcholem pomoci DFS a ulozi vysledek do promenne <code>cestaExistuje</code>. Vrati pocet navstivenych vrcholu.
 * @param vrchol1 prvni vrchol
 * @param vrchol2 druhy vrchol
 * @return pocet navstivenych vrcholu     
 *)                   
function TJedenTrezor_existujeCesta(var this: TJedenTrezor; vrchol1: longint; vrchol2: longint): longint;
var
  pocetNavstivenychVrcholu: longint;
  i: longint;
begin  
  pocetNavstivenychVrcholu := 0;
  
  for i := 0 to (length(this.prechodyMeziKlici) - 1) do begin
    this.prechodyMeziKlici[i, i] := BILA;
  end;
  this.cestaExistuje := false;
  pocetNavstivenychVrcholu := TJedenTrezor_dfs(this, vrchol1, vrchol2);
  
  TJedenTrezor_existujeCesta := pocetNavstivenychVrcholu;
end;

(*
 * Urci a vrati nejmensi pocet otoceni vedouci k otevreni trezoru pomoci postupneho pridavani vzestupne serazenych hran podle ohodnoceni do grafu bez hran. Hrana je pridana pouze, pokud mezi jejimi vrcholy v grafu zatim neexistuje cesta (zjistovano pomoci DFS)
 * @return nejmensi pocet otoceni vedouci k otevreni trezoru
 *)        
function TJedenTrezor_urciNejmensiPocetOtoceni(var this: TJedenTrezor): longint;
var
  hrana: THrana;
  predchoziPocetDosazitelnychKlicu: longint;
  pocetDosazitelnychKlicu: longint;
  soucetPouzitychHran: longint;
  nejmensiPocetOtoceni: longint;
  pocetOtoceni: longint;
  pocatek: ansistring;
  i, j: longint;

begin  
  TJedenTrezor_naplnPrechodyMeziKlici(this);
  TJedenTrezor_seradHrany(this, false);
  
  for i := 0 to (length(this.prechodyMeziKlici) - 1) do begin //Smazat vsechny prechody mezi klici (tj. hrany)
    this.prechodyMeziKlici[i, i] := BILA;
          
    for j := i + 1 to (length(this.prechodyMeziKlici[i]) - 1) do begin
      this.prechodyMeziKlici[i, j] := BILA;
      this.prechodyMeziKlici[j, i] := BILA;
    end;
  end;
  
  predchoziPocetDosazitelnychKlicu := 0;
  pocetDosazitelnychKlicu := 0;
  soucetPouzitychHran := 0;
  
  for i := 0 to (this.pocetHran - 1) do begin //Postupne doplnovat hrany, otestovat, zda uz neexistuje cesta mezi vrcholy doplnovane hrany (pokud existuje, hranu nedoplnime)
    hrana := this.hrany[i];
    
    pocetDosazitelnychKlicu := TJedenTrezor_existujeCesta(this, hrana.index1, hrana.index2); 
    if (NOT this.cestaExistuje) then begin
      this.prechodyMeziKlici[hrana.index1, hrana.index2] := hrana.ohodnoceni;
      this.prechodyMeziKlici[hrana.index2, hrana.index1] := hrana.ohodnoceni;
      soucetPouzitychHran := soucetPouzitychHran + hrana.ohodnoceni;
    end;
    
    if (pocetDosazitelnychKlicu >= this.pocetKlicu) then begin  //Pokud jsme pri urcovani cesty narazili na vsechny klice (tj. vrcholy grafu), muzeme skoncit
      break;
    end;
  end;
  
  nejmensiPocetOtoceni := MAXIMALNI_POCET_OTOCENI;
  pocetOtoceni := 0;
  pocatek := '0000';
  for i := 0 to (length(this.klice) - 1) do begin  //Urceni nejmensiho poctu otoceni od pocatecniho nastaveni trezoru (0000) k jednomu z klicu
    pocetOtoceni := TJedenTrezor_urciNejmensiPocetOtoceniMeziKlici(this, pocatek, this.klice[i]);
    if (pocetOtoceni < nejmensiPocetOtoceni) then begin
      nejmensiPocetOtoceni := pocetOtoceni;
    end;
  end;
  
  TJedenTrezor_urciNejmensiPocetOtoceni := soucetPouzitychHran + nejmensiPocetOtoceni;
end;
  
begin
  readln(pocetTrezoru);
       
  for i := 0 to (pocetTrezoru - 1) do begin
    readln(radka);
    TJedenTrezor_init(jedenTrezor, radka);
    writeln(TJedenTrezor_urciNejmensiPocetOtoceni(jedenTrezor));
  end;

end.