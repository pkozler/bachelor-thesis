Toto CD je souèástí bakaláøské práce na téma "Vytvoøení knihoven s definovaným rozhraním v jazycích C, C++, C# a FreePascal" na Katedøe informatiky a výpoèetní techniky Fakulty aplikovaných vìd Západoèeské univerzity v Plzni.
Autor: Petr Kozler
Datum: 23.06.2016

Popis adresáøové struktury:

Thesis - obsahuje adresáøe se soubory textu bakaláøské práce:
  tex - obsahuje zdrojový text práce pro sazbu v typografickém systému TeX spolu s dalšími nezbytnými daty
  pdf - obsahuje výstupní dokument sazby ve formátu PDF

Libraries - obsahuje adresáøe s pùvodní podobou zdrojových kódù (tj. v podobì pøed jejich uložením do XML dokumentù pomocí aplikace pro správu zdrojového kódu) vytvoøených knihoven a se zdrojovými kódy programového vybavení pro jejich testování:
  C - obsahuje mj. adresáø CLibrary se zdrojovými kódy knihoven v jazyce C a podadresáøem tests se zdrojovými kódy modulù pro jednotkové testy tìchto knihoven; adresáøe jsou vytvoøeny jako projekty vývojového prostøedí Netbeans 8.0.2
  CPlusPlus - obsahuje mj. adresáø CppLibrary se zdrojovými kódy knihoven v jazyce C++ a podadresáøem tests se zdrojovými kódy modulù pro jednotkové testy tìchto knihoven; adresáøe jsou vytvoøeny jako projekty vývojového prostøedí Netbeans 8.0.2
  CSharp - obsahuje mj. adresáø CsLibrary se zdrojovými kódy knihoven v jazyce C# a dále adresáø CsLibraryTest se zdrojovými kódy tøíd pro jednotkové testy; adresáøe jsou vytvoøeny jako projekty vývojového prostøedí Visual Studio Community 2015
  FreePascal - obsahuje mj. adresáø PasLibrary se zdrojovými kódy knihoven v jazyce Free Pascal a dále adresáø PasLibraryTest se zdrojovými kódy tøíd pro jednotkové testy; adresáøe jsou vytvoøeny jako projekty vývojového prostøedí Lazarus 1.4.4
  IOLibraryTestRunner - obsahuje zdrojové soubory PHP skriptu pro automatizované testování knihoven (ve všech použitých programovacích jazycích) urèených k provádìní vstupnì/výstupních operací*

CodeManager - je koøenovým adresáøem aplikace pro správu zdrojového kódu vytvoøené v jazyce Java, obsahuje mj. adresáøe:
  src - obsahuje balíky se zdrojovými kódy a dalšími soubory potøebnými pro spuštìní aplikace
  doc - obsahuje programátorskou dokumentaci vygenerovanou nástrojem Javadoc (uživatelská pøíruèka je pøiložena k textu bakaláøské práce)
  bin - obsahuje spustitelný .jar soubor aplikace a adresáø s daty (XML soubory)
  test - obsahuje tøídy pro jednotkové testy jádra aplikace (GUI bylo testováno manuálnì)

CodeConverter - obsahuje zdrojové soubory nástroje pro automatickou konverzi jednoduchých konstrukcí v kódu z jazyka Java do ostatních použitých jazykù (nástroj disponuje webovým rozhraním a logika je naprogramována v jazyce JavaScript)

*pozn.: všechny 4 adresáøe vytvoøených knihoven obsahují kromì uvedených podadresáøù též podadresáøe PrintStreamTest a ScannerTest, obsahující zdrojové kódy utilit pro testování knihoven urèených k IO operacím; tyto utility jsou poté využívány nástrojem pro automatizované testování