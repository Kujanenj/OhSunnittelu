# TODO

**yleiset**
- UNIT TESTIT :D
- Eikun oikeesti siis. Tehkää tekin niitä testejä.
- Oma namespace tässä vaiheessa aika must, myöhemmin ei enää jaksa

**toiminnalisuus**
- valmiin datan käsittely. (Jussi ja jemppu)
- QML (Riku_enHund_Rainio ja Veikko_kuhtuu_Hiltunen) 


## Git tips
**git remote update origin --prune**
- Päivittää locaalin listan remote brancheistä, että **git branch -a** pysyy perässä

**git checkout -b new_branch based_on_old_branch**
- Esim jos teet uuden featuren develop branchista, **git checkout -b feature develop**

**git push -u origin feature_branch** 
- Ekalla kerralla kun pusket uuden branchin githubiin, jotta upstream tulee asetettua oikein

**git checkout develop** && **git merge new-feature**
- Merge developiin
