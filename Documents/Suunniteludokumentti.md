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
  - #### Datahandler: // EI TOTEUTETTU
    - Käsittelee parsettua dataa halutulla tavalla. 
      - Esimerkiksi: Datan järjestäminen aakkosjärjestykseen
  - #### Calculator:
	- Tarjoaa rajapinnan erinäsiä laskuja varten.
	- Esim: Laske näiden tuloksien keskiaika.
	- Käytänössä ottaa sisään QVec<QVec<QString>> muotoisia tuloksia, ja sylkee ulos QStringejä, tai std::pareja.
	- Ongelma metodina calculateAnalytics, jonka voisi sijoittaa jonnekkin muualle.
	- Käyttää math.h, sillä sitä tarvitaan osaan laskuista.
	- Luotiin laskujen suorittamista varten.
  - #### AbstractListModel
  	- Suorittaa listmodeleitten datan päivittämisen qml, sekä sorttaamisen
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
        - Ei vielä varmuutta taulukon tyypistä
      - Kaaviot (Charts)
        - Näyttää erilaisia taulukoita, jotka generoidaan datan avulla
        
### Controller:
 - #### Datamodel:
	- Hallinnoi muita modelin moduuleita, ja jalostaa niiden toimintaa.
	- Ottaa ohjeensa controllerilta.
	- Käytännön tasolla siis kutsuu muiden moduulien metodeita.
	- Esim: doParse kutsuu parsersin metodia fullParse
	- Pitää dataa tallensa niin kauan, että se saadaan käsiteltyä ja talletettua.
	- Jatkossa tullaan yhdistämään perushaun toiminnallisuudet yhteen metodiin.
	- Tullaan myös uudelleen tekemään insert metodit, sillä ne ovat miltei samantyyppisiä.
	- höydyntää memory.h, sillä std::shared_ptr
	- Classi luotiin sitä varten, että saatiin koottua modelin moduulien tominnat yhteen rajapintaan.
  - #### Datamanager: //NIMETTY DATAMODELIKSI?
    - Kontrolloi dataa requesterin, parserin ja ui:n välillä
    - Toimii myös yhteydessä taulukkojen luomisen kanssa //lol eipä
  - #### Graphicsmanager: // EI TOTEUTETTU
    - Hoitaa graphien näyttämiseen tarvittavat operaatiot 
      - Esimerkiksi keskinopeuksien laskeminen, top-listojen luominen
      
### Data:
- #### AbstractDataBase:
	- Suorittaa databasen luomisen, avaamisen ja sulkemisen
- #### Database:
	- SQLite hyödyntävä SQL tietokanta, jonka avulla hiihtodataa tallennetaan
	- Mahdollistaa helpon haun ja sorttauksen SqlQueryiden avulla, mutta toteutus tapahtuu muualla
	- Luo taulut modeleille ja suorittaa niihin tallentamisen
	- Poistaa myös taulut, joka haun jälkeen ja käynnistyksessä
	- Periytetty abstraktista databasesta
	
### Tests: // :D Näähän meni hyvi.
- Yksikkötestit kaikille metodeille, joissa mahdollisuudet erroreihin



### Itsearviointi:

	- Miten suunnitelma on pitänyt?

	- Mitä muutoksia vielä tehdään?
	
	- Mitä muutoksia tehtiin aiempaan versioon?

## Minimitoiminnallisuudet "Perusvaatimukset"
- Tietyn vuoden kaikki tulokset
  - Otetaan mukaan vain tietyllä aikavälillä maaliin päässeet
    - Esimerkki: Vuosi 2015 - Aikaväli: 2-5 tuntia
- Rinnakkaisten vuosien/matkojen/sukupuolien/ikäsarjojen vertailu 
  - Esimerkki: Vuodet 2015 & 2016 rinnakkain
- Lasketaan tietylle vuodelle/vuosille osallistuvien määrä, voittajan & häviäjän ajat, sekä keskinopeudet
  - Esimerkki: Vuoden 2015-2018 osallistujat - Voittajan aika - Häviäjän aika - Kisan keskiaika/nopeus
- Lasketaan tiettyjen vuosien voittajien yhteiset keskiajat
  - Esimerkki: Vuosien 2015-2018 voittajien keskinopeudet
- Parhaan naisen/miehen sijoituus tietyllä aikavälillä
  - Esimerkki: Parhaan naisen sijoitus välillä 2010-2015 perinteisen 50km matkalla
- Tulosten järjestäminen seuran nimen/vuoden/sijoituksen/iän/sukupuolen/kansallisuuden/jne. mukaan
  - Esimerkki: Järjesää 2015 vuoden tulokset joukkueen nimen mukaan aakkosjärjestykseen
- Tulosten näyttäminen joukkueittain
  - Esimerkki: Lasketaan 4 samassa seurassa olevien ajat yhteen ja lasketaan sijoitukset joukkueille
- Virhetilanteiden hallitseminen
  - Liikaa tuloksia
  - Nimi alkaa pienellä alkukirjaimella
  - Tiettynä vuotena ei järjestetty tiettyä matkaa
  - Jne...
  
## Työnjako (alustava)
- Jussi
  - Parserin teko
  - Datahandlerin teko
  - Muut toiminnallisuudet
    
- Veikko
  - Requesterin teko
  - Yleistä fixailua
  - QML

- Riku
  - QML
  
- Jemppu

## Muuta
- Trello
  - Päivitämme trelloa suunnittelun aikataulutukseen 
  https://trello.com/invite/b/Wp3kg4Ow/89425dc8c3a6074faefcea4a7d8cfa78/ohjelmistojen-suunnittelu
  
    
