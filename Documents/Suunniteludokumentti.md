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
