# Suunnitteludokumentti

## Tiedostorakenteet

### Model:
  - #### Datamanager
    - Kontrolloi dataa requesterin, parserin ja ui:n välillä
    - Toimii myös yhteydessä taulukkojen luomisen kanssa
  - #### Graphicsmanager
    - Hoitaa graphien näyttämiseen tarvittavat operaatiot 
      - Esimerkiksi keskinopeuksien laskeminen, top-listojen luominen

### View:
  - #### QML
    - QML avulla voi piirtää grapheja, filtteröidä ja tarkastella tulosdataa, hakea erilaisia
    top-listoja, ja muita erikoisominaisuuksia
    - Jaettu moniin eri QML filuihin
### Controller:
  - #### Parser:
    - Parsii HTML datan
  - #### Requester:
    - Hoitaa datan requestauksen / pullaamisen finlandia-hiihto sivuilta
    - Toimii data requesterin kanssa, jolta pyytää datan filttereihin
### Data:
- Mahdollisesti lokaali SQL tietokanta, jossa tulokset nähtävillä tableissa 
- Toinen vaihtoehto tallentaa tulokset mappiin, josta tuloksia voi sortata key arvoilla
### Tests:
- Yksikkötestit kaikille metodeille, joissa mahdollisuudet erroreihin

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
