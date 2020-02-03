# Harjoitustyön dokumentti

## Tiedostorakenteet
  ### Scripts:
  - Requester eli Python Script, joka hakee dataa sivulta ja lähettää datan eteenpäin
    - Halutaanko, että requester postaa suoraan datan C++ parserille vai jonkun tiedostomuodon kautta hitaampi
  ### API:
  ### Model:
  ### View:
  - QML tehty UI, jonka avulla voi filtteröidä ja tarkastella tulosdataa
  ### Controller:
  - Parsiminen, datan vieminen QML, ...)
  ### Data:
  - Voidaan tallentaa SQL/mySQL, jos halutaan / Json? / Txt, josta mappiin tai muuhun C++ tietorakenteeseen
    - SQL rakenteen avulla helpompi käyttää QML?
    - Tekstitiedostoista lukeminen hitaampaa?
  ### Testit:
  - Tänne kaikki unitTestit ja muut testaukseen liittyvät asiat
  - Lähes kaikelle unittestit
    
## UML

Kaavio tulee tähän
    
## Toiminnallisuus vaatimukset
### Toiminnallisia vaatimukset (eli perusvaatimukset):
- Haetaan n vuoden tuloksista tietyn ajan sisällä oleva. Esimerkki: hae vuoden 2011 tuloksista hiihtäjät, jotka ovat olleet maalissa 2-5 h sisällä.
- Saman matkan tulosten vertailu kahdelta eri vuodelta.
- Kahden eri matkan tulosten vertailu samalta vuodelta.
- Näytetään kullekin vuodelle osallistujien määrä sekä voittajan ja viimeiseksi maaliin
tulleen ajat ja keskinopeudet jokaiselta matkalta.
- Näytetään visuaalisesti aikakehitys tietylle urheilijalle annetulta ajanjaksolta
- Näytetään annetulta ajanjaksolta keskinopeus sijoituksen mukaan. 
  - Esimerkki1: Mikä on ollut keskinopeus vuosien 2011-2016 voittajalla. 
  - Esimerkki2: mikä on ollut keskinopeus TOP 5 –urheilijoilla 2012-2017.
- Näytetään parhaan miehen/naisen sijoitus tietyllä aikavälillä. 
  - Esimerkki: hae parhaan naisen sijoitus välillä 2010-2018
- Järjestetään tietyn vuoden tulokset seuran nimen mukaan aakkosjärjestykseen.
- Huomioidaan mahdolliset virhetilanteet 
  - Esimerkkejä: nimi alkaa pienellä alkukirjaimella
  - Tiettynä vuonna ei ole ollut käyttäjän hakemaa matkaa.
- Näytetään urheilijoiden jakauma maittain
- Näytetään kymmenen parasta joukkuetta
  - Joukkue saadaan laskemalla 4 samassa seurassa olevan ajat yhteen
