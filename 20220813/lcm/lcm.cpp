#include <bits/stdc++.h>
using namespace std;

string ans[] = { "", "1", "2", "3", "4", "6", "6", "12", "15", "20", "30", "30", "60", "60", "84", "105", "140", "210", "210", "420", "420", "420", "420", "840", "840", "1260", "1260", "1540", "2310", "2520", "4620", "4620", "5460", "5460", "9240", "9240", "13860", "13860", "16380", "16380", "27720", "30030", "32760", "60060", "60060", "60060", "60060", "120120", "120120", "180180", "180180", "180180", "180180", "360360", "360360", "360360", "360360", "471240", "510510", "556920", "1021020", "1021020", "1141140", "1141140", "2042040", "2042040", "3063060", "3063060", "3423420", "3423420", "6126120", "6126120", "6846840", "6846840", "6846840", "6846840", "8953560", "9699690", "12252240", "19399380", "19399380", "19399380", "19399380", "38798760", "38798760", "58198140", "58198140", "58198140", "58198140", "116396280", "116396280", "116396280", "116396280", "140900760", "140900760", "157477320", "157477320", "232792560", "232792560", "232792560", "232792560", "281801520", "446185740", "446185740", "446185740", "446185740", "892371480", "892371480", "1338557220", "1338557220", "1338557220", "1338557220", "2677114440", "2677114440", "2677114440", "2677114440", "2677114440", "2677114440", "3375492120", "3375492120", "5354228880", "5354228880", "5354228880", "5354228880", "5354228880", "5354228880", "6750984240", "6750984240", "7216569360", "7216569360", "8172244080", "12939386460", "13385572200", "13831757940", "13831757940", "25878772920", "25878772920", "38818159380", "38818159380", "41495273820", "41495273820", "77636318760", "77636318760", "82990547640", "82990547640", "82990547640", "82990547640", "82990547640", "82990547640", "155272637520", "155272637520", "165981095280", "165981095280", "165981095280", "165981095280", "165981095280", "165981095280", "209280511440", "209280511440", "232908956280", "232908956280", "388181593800", "401120980260", "414952738200", "414952738200", "414952738200", "802241960520", "802241960520", "1203362940780", "1203362940780", "1203362940780", "1203362940780", "2406725881560", "2406725881560", "2406725881560", "2406725881560", "2406725881560", "2406725881560", "2872543794120", "2872543794120", "4813451763120", "4813451763120", "4813451763120", "4813451763120", "4813451763120", "4813451763120", "5745087588240", "5745087588240", "6141300525360", "6141300525360", "7220177644680", "7220177644680", "12033629407800", "12033629407800", "12033629407800", "12033629407800", "12033629407800", "12033629407800", "14440355289360", "14841476269620", "24067258815600", "24067258815600", "24067258815600", "29682952539240", "29682952539240", "44524428808860", "44524428808860", "44524428808860", "44524428808860", "89048857617720", "89048857617720", "89048857617720", "89048857617720", "98675761143960", "98675761143960", "103489212907080", "103489212907080", "178097715235440", "178097715235440", "178097715235440", "178097715235440", "197351522287920", "197351522287920", "206978425814160", "206978425814160", "222622144044300", "222622144044300", "267146572853160", "267146572853160", "445244288088600", "445244288088600", "445244288088600", "445244288088600", "493378805719800", "493378805719800", "534293145706320", "534293145706320", "890488576177200", "890488576177200", "890488576177200", "890488576177200", "986757611439600", "986757611439600", "1034892129070800", "1217001054108840", "1217001054108840", "1825501581163260", "1825501581163260", "1914550438780980", "1914550438780980", "3651003162326520", "3651003162326520", "3829100877561960", "3829100877561960", "3829100877561960", "3829100877561960", "4243057729190280", "4243057729190280", "7302006324653040", "7302006324653040", "7658201755123920", "7658201755123920", "7658201755123920", "7658201755123920", "8486115458380560", "8486115458380560", "9127507905816300", "9127507905816300", "10953009486979560", "10953009486979560", "18255015811632600", "18255015811632600", "19145504387809800", "19145504387809800", "19145504387809800", "19145504387809800", "21906018973959120", "21906018973959120", "36510031623265200", "36510031623265200", "38291008775619600", "38291008775619600", "38291008775619600", "38291008775619600", "42430577291902800", "42430577291902800", "42430577291902800", "52331045326680120", "54765047434897800", "78496567990020180", "78496567990020180", "78496567990020180", "78496567990020180", "156993135980040360", "156993135980040360", "156993135980040360", "156993135980040360", "171597148629346440", "171597148629346440", "179967741245412120", "179967741245412120", "313986271960080720", "313986271960080720", "313986271960080720", "313986271960080720", "343194297258692880", "343194297258692880", "359935482490824240", "359935482490824240", "392482839950100900", "392482839950100900", "470979407940121080", "470979407940121080", "784965679900201800", "784965679900201800", "784965679900201800", "784965679900201800", "857985743146732200", "857985743146732200", "941958815880242160", "941958815880242160", "1569931359800403600", "1569931359800403600", "1569931359800403600", "1569931359800403600", "1715971486293464400", "1715971486293464400", "1799677412454121200", "1799677412454121200", "1799677412454121200", "1799677412454121200", "2354897039700605400", "2354897039700605400", "2354897039700605400", "2459559130353965640", "2573957229440196600", "3689338695530948460", "3689338695530948460", "3689338695530948460", "4709794079401210800", "7378677391061896920", "7378677391061896920", "7378677391061896920", "7378677391061896920", "7378677391061896920", "7378677391061896920", "8320636206942139080", "8320636206942139080", "14757354782123793840", "14757354782123793840", "14757354782123793840", "14757354782123793840", "14757354782123793840", "14757354782123793840", "16641272413884278160", "16641272413884278160", "18446693477654742300", "18446693477654742300", "22136032173185690760", "22136032173185690760", "36893386955309484600", "36893386955309484600", "36893386955309484600", "36893386955309484600", "36893386955309484600", "36893386955309484600", "44272064346371381520", "44272064346371381520", "73786773910618969200", "73786773910618969200", "73786773910618969200", "73786773910618969200", "73786773910618969200", "73786773910618969200", "83206362069421390800", "83206362069421390800", "83206362069421390800", "83206362069421390800", "110680160865928453800", "110680160865928453800", "110680160865928453800", "110680160865928453800", "110680160865928453800", "110680160865928453800", "147573547821237938400", "147573547821237938400", "221360321731856907600", "221360321731856907600", "221360321731856907600", "221360321731856907600", "221360321731856907600", "221360321731856907600", "249619086208264172400", "391069901726280536760", "391069901726280536760", "391069901726280536760", "391069901726280536760", "391069901726280536760", "391069901726280536760", "435341966072651918280", "435341966072651918280", "782139803452561073520", "782139803452561073520", "782139803452561073520", "782139803452561073520", "782139803452561073520", "782139803452561073520", "870683932145303836560", "870683932145303836560", "977674754315701341900", "977674754315701341900", "1173209705178841610280", "1173209705178841610280", "1955349508631402683800", "1955349508631402683800", "1955349508631402683800", "1955349508631402683800", "1955349508631402683800", "1955349508631402683800", "2346419410357683220560", "2346419410357683220560", "3910699017262805367600", "3910699017262805367600", "3910699017262805367600", "3910699017262805367600", "3910699017262805367600", "3910699017262805367600", "4353419660726519182800", "4353419660726519182800", "4500993208547757121200", "4500993208547757121200", "5866048525894208051400", "5866048525894208051400", "5866048525894208051400", "5866048525894208051400", "5866048525894208051400", "5866048525894208051400", "7821398034525610735200", "7821398034525610735200", "11732097051788416102800", "11732097051788416102800", "11732097051788416102800", "11732097051788416102800", "11732097051788416102800", "11732097051788416102800", "13060258982179557548400", "13060258982179557548400", "13502979625643271363600", "13502979625643271363600", "13502979625643271363600", "13502979625643271363600", "14727526086287586171600", "23073124201850551668840", "23073124201850551668840", "23855264005303112742360", "23855264005303112742360", "23855264005303112742360", "23855264005303112742360", "23855264005303112742360", "23855264005303112742360", "46146248403701103337680", "46146248403701103337680", "47710528010606225484720", "47710528010606225484720", "47710528010606225484720", "47710528010606225484720", "47710528010606225484720", "47710528010606225484720", "57682810504626379172100", "57682810504626379172100", "69219372605551655006520", "69219372605551655006520", "115365621009252758344200", "115365621009252758344200", "119276320026515563711800", "119276320026515563711800", "119276320026515563711800", "119276320026515563711800", "138438745211103310013040", "138438745211103310013040", "230731242018505516688400", "230731242018505516688400", "238552640053031127423600", "238552640053031127423600", "238552640053031127423600", "238552640053031127423600", "238552640053031127423600", "238552640053031127423600", "265558599304317670150800", "265558599304317670150800", "346096863027758275032600", "346096863027758275032600", "357828960079546691135400", "357828960079546691135400", "357828960079546691135400", "357828960079546691135400", "461462484037011033376800", "461462484037011033376800", "692193726055516550065200", "692193726055516550065200", "715657920159093382270800", "" };

int n;

int main() {
	freopen("lcm.in", "r", stdin);
	freopen("lcm.out", "w", stdout);
	cin >> n;
	cout << ans[n] << endl;
	return 0;
}

