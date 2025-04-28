```markdown
**Kasa fiskalna w C++**

Ten projekt to prosta implementacja kasy fiskalnej w języku C++. Program pozwala użytkownikowi zarządzać gotówką, w tym dodawaniem i wyjmowaniem banknotów oraz monet, a także wyświetlaniem aktualnego stanu kasy.

### Główne funkcje:
- **Otwieranie i zamykanie kasy**: Użytkownik może otworzyć lub zamknąć kasę, co ogranicza dostęp do operacji z gotówką.
- **Dodawanie gotówki**: Możliwość dodawania banknotów i monet różnych nominałów.
- **Wyjmowanie gotówki**: Użytkownik może wyjmować banknoty i monety, a program sprawdza, czy wystarczająco środków na wykonanie operacji.
- **Wyświetlanie stanu kasy**: Program wyświetla aktualny stan kasy, w tym całkowitą kwotę gotówki i ilość każdego nominału.
- **Zapis i ładowanie danych**: Dane o stanie kasy są zapisywane w pliku `data.txt`, co pozwala na przywrócenie stanu przy następnym uruchomieniu programu.

### Używane technologie:
- **Język programowania**: C++
- **Biblioteki**: `<iostream>`, `<fstream>`

### Instalacja i uruchomienie:
1. Sklonuj repozytorium na swój komputer.
2. Otwórz projekt w środowisku programistycznym obsługującym C++.
3. Skompiluj i uruchom program.
