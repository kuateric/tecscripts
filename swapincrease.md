## Linux – Swap erweitern
kopiert von: https://technik.blogbasis.net/linux-swap-erweitern-19-11-2013 
- Swap erstellen
Zunächst erstellen wir mit Hilfe des „dd“-Kommandos eine neue Datei (/swap) mit der gewünschten Größe (hier: 1G * 4 = 4G):
```bat
sudo dd if=/dev/zero of=/swap bs=1G count=16
```
Die Größe lässt sich einfach über den „count“ Parameter im Gigabyte-Bereich verändern. Mit dem Parameter „bs“ lässt sich die Blöckgröße ändern. (z.B. 1M ; 1K …).

- Als nächsten müssen wir die Datei mit dem Swap-Dateisystem formatieren. Das klappt mit:
```bat
sudo mkswap /swap
```

- Danach noch kurz die Rechte anpassen:
```bat
sudo chmod 0600 /swap && sudo chown root:root /swap
```
- Swap aktivieren
Um den Swap an das System „anzuschließen“ genügt der folgende Befehl:
```bat
sudo swapon /swap
```
- Das Ergebnis lässt sich leicht durch einen Aufruf von
```bat
free -h
```
nachprüfen (Swap-Zeile).

- Möchte man den Swap auch nach einem Neustart wieder automatisch eingebunden bekommen, dann muss man eine Zeile an die /etc/fstab anhängen:
```bat
sudo cp /etc/fstab /etc/fstab.bak
echo '/swap none swap sw 0 0' | sudo tee -a /etc/fstab
```
