program OslavaZapoctu;

const
  DEFAULT_ARRAYLIST_CAPACITY = 1024;
  
type
  TStringTokenizer = record
    stringToSplit: ansistring;
    splitCharacter: char;
    remainingString: ansistring;
  end;
  TArrayListData = array of longint;
  TArrayList = record
    data: TArrayListData;
    size: longint;
    capacity: longint;
  end;
  TSilyDrinku = array of longint;
  TTabulka = array of array of longint;

var
  radka: ansistring;
  
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
 * @param number the number to be added to this arraylist
 *)
procedure TArrayList_add(var this: TArrayList; number: longint);
begin
  if (this.size < this.capacity - 1) then begin
    this.data[this.size] := number;
    inc(this.size);
  end
  else begin
    this.capacity := this.capacity * 2;
    setLength(this.data, this.capacity); 
  end;             
end;

function TArrayList_get(var this: TArrayList; index: longint): longint;
begin
  if ((index >= 0) AND (index < this.size)) then begin
    TArrayList_get := this.data[index];
  end
  else begin
    TArrayList_get := -1;
  end;
end;

procedure TStringTokenizer_init(var this: TStringTokenizer; stringToSplit: ansistring; splitCharacter: char);
begin
  this.stringToSplit := stringToSplit;
  this.remainingString := stringToSplit;
  this.splitCharacter := splitCharacter;
end;

function TStringTokenizer_hasNextToken(var this: TStringTokenizer): boolean;
begin
  TStringTokenizer_hasNextToken := (length(this.remainingString) = 0);
end;

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
 * Urci a vrati celkovy pocet drinku obou holek dynamickym programovanim 
 * @param kapacitaHolky kapacita jedne holky (kolik snese jednotek alkoholu)
 * @param silyDrinku sily jednotlivych drinku, postupne jak prichazeji (jak je holky piji)
 * @return celkovy pocet drinku obou holek              
 *)   
function urciPocetDrinku(kapacitaHolky: longint; silyDrinku: TSilyDrinku): longint;
var
  tabulka: TTabulka;
  mnozinaTatoIterace: TArrayList;
  mnozinaDalsiIterace: TArrayList;
  pomocnaMnozina: TArrayList;
  celkemVypito: longint;
  pocetVypitychDrinku: longint;
  pomocna: longint;
  i: longint;

begin
  setLength(tabulka, length(silyDrinku), kapacitaHolky + 1);
  TArrayList_init(mnozinaTatoIterace);
  TArrayList_init(mnozinaDalsiIterace);  
  celkemVypito := 0;
  pocetVypitychDrinku := 0;
  pomocna := 0;
  
  TArrayList_add(mnozinaTatoIterace, 0);
  
  for pocetVypitychDrinku := 0 to (length(silyDrinku) - 1) do begin
    celkemVypito := celkemVypito + silyDrinku[pocetVypitychDrinku];
    
    for i := 0 to (TArrayList_size(mnozinaTatoIterace) - 1) do begin
      if ((celkemVypito - TArrayList_get(mnozinaTatoIterace, i) <= kapacitaHolky) AND (tabulka[pocetVypitychDrinku][TArrayList_get(mnozinaTatoIterace, i)] = 0)) then begin
        TArrayList_add(mnozinaDalsiIterace, TArrayList_get(mnozinaTatoIterace, i));
        tabulka[pocetVypitychDrinku][TArrayList_get(mnozinaTatoIterace, i)] := TArrayList_get(mnozinaTatoIterace, i);
      end;
      
      pomocna := TArrayList_get(mnozinaTatoIterace, i) + silyDrinku[pocetVypitychDrinku];
      if ((pomocna <= kapacitaHolky) AND (tabulka[pocetVypitychDrinku][pomocna] = 0)) then begin
        TArrayList_add(mnozinaDalsiIterace, pomocna);
        tabulka[pocetVypitychDrinku][pomocna] := TArrayList_get(mnozinaTatoIterace, i);
      end;         
    end;
    
    if (TArrayList_isEmpty(mnozinaDalsiIterace)) then begin
      break;
    end
    else begin
      TArrayList_clear(mnozinaTatoIterace);
      pomocnaMnozina := mnozinaTatoIterace;
      mnozinaTatoIterace := mnozinaDalsiIterace;
      mnozinaDalsiIterace := pomocnaMnozina;
    end;
  end;
  
  urciPocetDrinku := pocetVypitychDrinku;
end;  

(*
 * Zpracuje radku s kapacitou holek a silou jednotlivych drinku a vrati maximalni pocet drinku, ktere holky muzou vypit
 * @return maximalni pocet drinku, ktere holky muzou vypit
 *)        
function zpracujRadku(radka: ansistring): longint;
var
  st: TStringTokenizer;
  pocetDrinku: longint;
  silyDrinku: TSilyDrinku;
  kapacitaHolky: longint;
  kod: longint;
  i: longint;
begin
  TStringTokenizer_init(st, radka, ' ');
  pocetDrinku := TStringTokenizer_countTokens(st) - 2;
  setLength(silyDrinku, pocetDrinku);
  val(TStringTokenizer_nextToken(st), kapacitaHolky, kod);
      
  for i := 0 to (pocetDrinku - 1) do begin
    val(TStringTokenizer_nextToken(st), silyDrinku[i], kod);
  end;

  zpracujRadku := urciPocetDrinku(kapacitaHolky, silyDrinku);
end;

begin
  readln(radka);
  while (NOT (radka = '0')) do begin
    writeln(zpracujRadku(radka));
    readln(radka);
  end; 
end.