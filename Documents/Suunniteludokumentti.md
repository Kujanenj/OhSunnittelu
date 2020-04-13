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
	


## Muuta
- Trello
  - Päivitämme trelloa suunnittelun aikataulutukseen 
  https://trello.com/invite/b/Wp3kg4Ow/89425dc8c3a6074faefcea4a7d8cfa78/ohjelmistojen-suunnittelu
  
    
