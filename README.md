## TODO

# yleiset
**Konkreettiset jutut mitä teherää**: 
- Bugfixit ja testaus ja cleanup. (Rollback erroreis ja käsittely paikallisesti)
- Riku hoitaa requesteri
- uus view Clässi ( ehkä useita?) nämä siis syöttäis dataa qml puolelle, ja olis pääsy modelille. :D
- Rajapinnat: Luodaan model mainissa -> luodaan view mainissa ja annetaan parametrinä modelin pointteri -> luodaan controller mainissa ja annetaan parametreinä modelin ja viewin pointterit
- Graaffit alustava
- Datan ottaminen databasesta ulos
ja mastiffit

*muut*
- UNIT TESTIT :D
- Filteröinti SQL:ssä
- Whitespacet pois :DDDD
- (Jos on tylsää ja paljon aikaa nii yli 10 tunnin hiihtojen järjestäminen oikein ja databasen yhtenäistäminen, koska joissakin tuloksissa sadasosia ja kymmenyksiä)

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
