# TODO

**yleiset**

- Requesteriin ja backendii jää nyt  olioita roikkumaan. New:llä luodut oliot on ok, mutta pitää kattoa että ne poistuu.
- Vaihtaa kaikki new:llä luodut smart pointteriksi? 
- UNIT TESTIT :D
- kommentoinnit (Ainakin requester ja bäckend"
- Nimetä bäckend uudestaan. Esim manager?
- Oma namespace tässä vaiheessa aika must, myöhemmin ei enää jaksa

**toiminnalisuus**
- Yhteys qml:n ja bäckendin välis, eli siis saa ne tekstikenttien datat ulos.
- Joku tulkki valmiille datalle. (Uus clässi)



# OHJEET MONNEILLE
- Ladatkaa python 3.X versio ja laittakaa asennuksessa "Add python 3.X to PATH", jotta Qt löytää .exen automaattisesti
- Ladatkaa get-pip.py täältä: https://bootstrap.pypa.io/get-pip.py
- Avatkaa cmd get-pip.py polusta ja kirjottakaa "python get-pip.py"
- Pythonin ja pip:in oikeasta asennuksesta saa varmuuden kun laittaa cmd "python -V / pip -V" - Jos ei palauta mitään jotain väärin
- Tän jälkee kirjottakaa pip install selenium ja jos kaikki oikein pitäs lataa jotai :D
- PhantomJS.exe löytyy Python_Script folderista, täyttäkää se polku kuntoon "Python_Script/main.py" filuun
- Täyttäkää polut kuntoon Requester/Scripts/main.cpp filusta niin, että main.cpp runnatessa saatte data.txt filun. Error.txt filusta näkee maholliset errorit runnatessa.

## Git tips
**git remote update origin --prune**
- Päivittää locaalin listan remote brancheistä, että **git branch -a** pysyy perässä

**git checkout -b new_branch based_on_old_branch**
- Esim jos teet uuden featuren develop branchista, **git checkout -b feature develop**

**git push -u origin feature_branch** 
- Ekalla kerralla kun pusket uuden branchin githubiin, jotta upstream tulee asetettua oikein

**git checkout develop** && **git merge new-feature**
- Merge developiin
