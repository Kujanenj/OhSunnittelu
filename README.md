## TODO

# YLEISET
**Konkreettiset jutut mitä teherää**:

  #16.3.2020

- Dataview poistetaan. 
- Uml kaaviot



# Dokumentaatio
* yleisiä pointteja:
- Pitää kuvata mitä teknologioita on käytetty ja miksi. Miksi ei selenium?
- koska paska
- komponentin vastuu ja tarkoitus.

* Mitä dokumentoidaan ja kuka hoitaa.
- Kaikki komponentit
- Jussi hoitaa: datamodel, calculator
- Riku: kahvi ja gintonic jäillä. Lisäksi ottaa myös ranskalaiset lihapyöryköillä. Controller, qml osa 1 mielellään.
- Veikko: Ei juo kahvia, mutta  lisäksi requester, database, listmodelit ULKOINEN RAJAPINTA!!!
- Jemppu: Parser,  qml osa 2. Toimikaa RikuR:n kanssa yhessä. 

- Ence ei kiinnosta ketää
- Miksi milla pilkkaa meitä? :C

* Rajapinnoista
- Datan kulku järjestelmässä. Model->req->parser->db? muistaakseni
- Modeli on fasaani.

* itsearviointi
## Mitä kaikkee tulee
- Filtterit analyticsii (Vuosi)
- Kolmas pöytä analyticsii, ei voi olla nimellä table_3 tai mitään muuta vammaista.
- Tarvii noin 1/3 tai 1/4 sivun oikeasta laidasta. 
- Tulee vaan vasemmalle niinku noi matkat. Ylös headeriksi alkuvuosi-loppuvuosi
- Datat päivitetää sitten kun filtteri päivitetää 

- Yksittäisen ihmisen haku. 
- Vois niinku klikata jotai ja sitten niinku tehtääs joku haku. Mutta ei niinku sillei ylikirjoottaasi sitä  table_1 eikä table_2 eikä mitään muutakaan.


- Graaffit 
- Matka ja vuosi valikko.
- Pie chartti, osallistujat matkoille suhteessa. 
- Ränkki x aika y. 
- X akseli vuodet y akseli aika (?)
- Miesten sijoitukset sinisel, naisten punaisella. Saadaan tästä vielä joku sosiaalisyyte koska sovinsimi. Mutta minkä sille voi jos ne naiset on paskempia?
- PieChartti miehistä naisista.
- Graaffit .jpg :;D jos jaksaa
* MUUT
- Listmodel ja analytics model pitää yhistää jotenki. Abstrakti? periytys? Tähän sit liittyy toi insert into table basga
- Insert into table privateksi. Ja parseri kans.



- Whitespacet pois :DDDD whitespacet saa kyl jäädä mun mielestä
- (Jos on tylsää ja paljon aikaa nii yli 10 tunnin hiihtojen järjestäminen oikein ja databasen yhtenäistäminen, koska joissakin tuloksissa sadasosia ja kymmenyksiä)

**Rajapinnat**
- Model: Annan sulle dataa tiettyjen vaatimusten mukaan.
- Osaan myös hakea dataa ja tallentaa sen ;)
- Controller: Nappulat.



## Git tips
**git remote update origin --prune**
- Päivittää locaalin listan remote brancheistä, että **git branch -a** pysyy perässä

**git checkout -b new_branch based_on_old_branch**
- Esim jos teet uuden featuren develop branchista, **git checkout -b feature develop**

**git push -u origin feature_branch** 
- Ekalla kerralla kun pusket uuden branchin githubiin, jotta upstream tulee asetettua oikein

**git checkout develop** && **git merge new-feature**
- Merge developiin
