# Suunnitteludokumentti

## Tiedostorakenteet

### Model:
  - #### Parser:
    - Parsii HTML datan
    - Muodostaa parsitusta datasta vectorin
    - Ottaa käskyn parsimiseen DataModelilta
    - fullParse kutsuu kaikkia parsimiseen tarvittavia komentoja: (readFile), parseToTable, parseTable, formListedData
    - readFile tarkoitettu ainoastaan testaamiseen, eikä sitä kutsuta muuten
    - Säilyttää data vectorin tyhjäyspyyntöön asti
    - Palauttaa luodun vectorin pyydettäessä
  - #### Requester:
    - Hoitaa datan requestauksen / pullaamisen finlandia-hiihto sivuilta
    - Toimii data requesterin kanssa, jolta pyytää datan filttereihin
  - #### Calculator:
	- Tarjoaa rajapinnan erinäsiä laskuja varten.
	- Esim: Laske näiden tuloksien keskiaika.
	- Käytänössä ottaa sisään QVec<QVec<QString>> muotoisia tuloksia, ja sylkee ulos QStringejä, tai std::pareja..
	- Käyttää math.h, sillä sitä tarvitaan osaan laskuista.
	- Luotiin laskujen suorittamista varten.
  - #### AbstractListModel
  	- Suorittaa listmodeleitten datan päivittämisen qml, sekä sorttaamisen.
	- Kantaluokka kaikille modeleille.
  - #### AnalyticsModel:
	- Sisältää analytics rolejen alustamisen qml varten, jotta taulukkoihin inserttaaminen onnistuu
	- Periytetty AbstractListModelista
  - #### ResultModel:
	- Sisältää results rolejen alustamisen qml varten, jotta taulukkoihin inserttaaminen onnistuu
	- Periytetty AbstractListModelista
### View:
  - #### QML
    - QML avulla voi piirtää grapheja, filtteröidä ja tarkastella tulosdataa, hakea erilaisia
    top-listoja, ja muita erikoisominaisuuksia
    - Jaettu moniin eri QML filuihin
      - Etusivu (Search tab)
        - Näyttää perushaku ikkunan, josta voi hakea tietyillä filttereillä dataa
      - Tulokset
        - Näyttää hausta saadut tulokset, jonkin tyyppisessä taulukossa
      - Kaaviot (Charts)
        - Näyttää erilaisia taulukoita, jotka generoidaan datan avulla
        
### Controller:
 - #### Datamodel:
	- Hallinnoi muita modelin moduuleita, ja jalostaa niiden toimintaa.
	- Ottaa ohjeensa controllerilta.
	- Käytännön tasolla siis kutsuu muiden moduulien metodeita.
	- Esim: doParse kutsuu parsersin metodia fullParse
	- Pitää dataa tallensa niin kauan, että se saadaan käsiteltyä ja talletettua.
	- höydyntää memory.h, sillä std::shared_ptr
	- Classi luotiin sitä varten, että saatiin koottua modelin moduulien tominnat yhteen rajapintaan.


      
### Data:
- #### AbstractDataBase:
	- Suorittaa databasen luomisen, avaamisen ja sulkemisen
	- Baseclass kaikille mahdollisille databeisseille.
- #### Database:
	- SQLite hyödyntävä SQL tietokanta, jonka avulla hiihtodataa tallennetaan
	- Mahdollistaa helpon haun ja sorttauksen SqlQueryiden avulla, mutta toteutus tapahtuu muualla
	- Luo taulut modeleille ja suorittaa niihin tallentamisen
	- Poistaa myös taulut, joka haun jälkeen ja käynnistyksessä
	- Periytetty abstraktista databasesta
	

### Refaktorointi ja muutokset:
- Yksikkötestien poisto
- Graphicsmanager jätetty pois tarpeettomana.
- Datahandler jätetty pois tarpeettomana.
- ViewClass jätetty pois tarpeettomana.
- Datamanegrin metodien karsiminen ja yhdistely. Esim insert database metodit yhdistetty yhdeksi yleiseksi metodiksi
- Calculaattorien metodien yleistys. Esim calculateCountries ja calculateDistances yhdistetty yleiseksi metodiksi.

### Itsearviointi:

	* Miten suunnitelma on pitänyt?
	- Yleisesti ottaen suunnitelma on pitänyt hyvin.
	- Alussa oli helppo lähteä tekemään erinäisiä moduuleita, kun niiden tarkoitus oli suunniteltu valmiiksi.
	- Esimerkiksi parser, requester ja controller suuniteltiin alusta asti.

	* Mitä muutoksia vielä tehdään?
	- Datamodelin refactorointia. 
	- InsertData funktioiden yhdistämistä.
	- View class tullaan todennäköisesti poistamaan turhana.
	
	* Mitä muutoksia tehtiin aiempaan versioon?
	- Alunperin requester käytti pythonia ja seleniumia.
	- SQL ei ollut mukana alkuperäisessä suunnitelussa.
	- Unit testejä ei olla pidetty yllä.
	
## Ohjelman toiminta ja kuvat

- ### Etusivu
![Etusivu](https://i.imgur.com/tAUSJ0D.png)
#### Toiminta 
Etusivulta käyttäjä voi suorittaa tuloshaun monilla eri filttereillä.
Filtterit:
- Useita vuosia samaan aikaan
- Monia eri hiihtomatkoja
- Rajata sukupuolia
- Tiettyjen ikäsarjojen haku
- Etu- ja sukunimi haut
- Paikkakunta filtteri
- Kansallisuus
- Joukkue

---

- ### Tulokset
![Tulokset](https://i.imgur.com/j5n0qtV.png)
Tulokset sivulla käyttäjä näkee hakemansa tulokset ja pystyy järjestämään tuloksia eri järjestyksiin.
Käyttäjä pystyy hakemaan tietylle henkilölle yksilöllisen haun klikkaamalla oikea hiirenpainiketta tuloksen kohdalla ja painalla
"Show all personal results". Tämä toiminto laskee yksilölliset tulokset koko urheilijan uralta ja siirtää näkymän statistiikka sivulle.
Lisäksi käyttäjä pystyy tarkastelemaan tuloksia 1-9 tunnin aikavälillä ja näyttämään sijoitukset 10 - 1500 asti.
Mahdolliset järjestystavat:
- Vuosi
- Matka
- Aika
- Sijoitus / Sijoitus miehet / Sijoitus naiset
- Sukupuoli
- Nimi
- Kaupunki
- Kansallisuus
- Ikä
- Joukkue

---

- ### Statistiikat
![Analytiikat](https://i.imgur.com/YfNx7An.png)
Statistiikat sivulta käyttäjä pystyy tarkastelemaan eri vuosien ja matkojen keskiaikoja, keskinopeuksia, osallistujamääriä, nopeimpia ja hitaimpia aikoja, top 3 urheilijat ja matkan parhaan joukkueen. Lisäksi statistiikka sivulla on yksilöhaun tulokset mikäli käyttäjä on suorittanut yksilöhaun.

---

- ### Kaaviot 1
![Kaaviot 1](https://i.imgur.com/sj6lH57.png)
Kaaviot 1 sivulla käyttäjä näkee 4 eri taulukkoa. Ensimmäinen taulukko kuvaa aikaeroa parhaan urheilijan ja 9 hänen jälkeen tulevan välillä. Toinen taulukko oikealla ylhäällä kuvaa parhaita aikoja tietyillä matkoilla naisten ja miesten välillä. Vasemmalla alhaalla on taulukko, jossa käyttäjä pystyy tarkastelemaan urheilijoiden kansallisuus jakaumaa tietyllä matkalla ja vuodella. Oikealla alhaalla on neljäs graafi, joka näyttää osallistujamäärän suhteen tietyille matkoille tietyllä vuodella.
Kaikkia graafeja pystyy muokkaamaan dynaamisten dropdownboxien avulla.

---

- ### Kaaviot 2
![Kaaviot 2](https://i.imgur.com/x0bxXO7.png)
Kaaviot 2 sivulla ylempi taulukko kuvaa kaikkien vuosien matkojen parhaiden 5 urheilijan keskinopeudet. Alempi taulukko näyttää 10 parhaan joukkueen keskiarvolliset tulokset tietyllä matkalla ja tietyllä vuodella.
Tässäkin graafeja pystyy muokkaamaan dynaamisten dropdownboxien avulla.

---

### Muuta
- Trello
  - Päivitämme trelloa suunnittelun aikataulutukseen 
  https://trello.com/invite/b/Wp3kg4Ow/89425dc8c3a6074faefcea4a7d8cfa78/ohjelmistojen-suunnittelu
  
    
