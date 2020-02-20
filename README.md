## TODO

# yleiset
**Konkreettiset jutut mitä teherää**: 
- Sorttaus databasee
- Bugfixit ja testaus ja cleanup. (Rollback erroreis ja käsittely paikallisesti)
- Riku hoitaa requesteri, jemppu parseri, veikko_kuhtuu_ hoitaa manageri, ja minä (jussi) ottaa sql.
- uus view Clässi ( ehkä useita?) nämä siis syöttäis dataa qml puolelle, ja olis pääsy modelille. :D
- Rajapinnat: Controllerin alla model ja view, viewin alla modeli. Suomeksi siis->Controlleri ottaa constructioris model ja view oliot,
ja view ottaa model olion. (Pointterin tietysti :D) 
-Keskitetty model clässi, jonka alla muut modelin paskat.
ja mastiffit

*muut*
- UNIT TESTIT :D
- Graaffit
- MultiYear (Controlleris) 
**Rajapinnat**
- View: käskytys controllerilta, joku configi?
- yhteys Qpropertyllä qml:ää, mitä se sitten meinaakaan.
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
