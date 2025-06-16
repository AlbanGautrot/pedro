# Mass Mailing PowerShell Script

Ce script permet d’envoyer des e-mails de masse personnalisés à l’aide d’un template HTML et d’un fichier CSV de contacts.  

## Diagramme de flux

```mermaid
flowchart TD
    A[Démarrer] --> B[Charger configuration & templates]
    B --> C[Afficher formulaire de sélection de template]
    C --> D{Template valide ?}
    D -- Non --> E[Erreur & arrêt]
    D -- Oui --> F[Importer CSV]
    F --> G{CSV importé et non vide ?}
    G -- Non --> E
    G -- Oui --> H{Colonnes requises présentes ?}
    H -- Non --> E
    H -- Oui --> I[Lire template HTML]
    I --> J{Fichier HTML existant ?}
    J -- Non --> E
    J -- Oui --> K[Connexion SMTP]
    
    subgraph BoucleEnvoi [Boucle d’envoi des e-mails]
      direction TB
      L[Pour chaque contact] --> M[Personnaliser corps HTML]
      M --> N[Envoyer l’e-mail]
      N --> O{Succès ?}
      O -- Oui --> P[Logger succès]
      O -- Non --> Q[Logger erreur individuelle]
      P --> L
      Q --> L
    end

    K --> BoucleEnvoi
    BoucleEnvoi --> R[Déconnexion SMTP]
    R --> S[Générer résumé & vider CSV]
    S --> T[Fin]
