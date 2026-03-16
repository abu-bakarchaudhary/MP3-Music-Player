# 🎵 MP3 Music Player

> A terminal-based C++ music player — manage playlists, browse directories, and play audio files entirely from the command line.

![C++](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=cplusplus&logoColor=white)
![Interface](https://img.shields.io/badge/Interface-Terminal-lightgrey?style=flat-square)
![Platform](https://img.shields.io/badge/Platform-Windows-blue?style=flat-square)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=flat-square)

---

## 📌 Overview

No GUI. No dependencies. Just a C++ program that runs entirely in the terminal and lets you manage and play your music through keyboard commands.

MP3 Music Player gives you full playlist control from the command line — navigate directories to find audio files, build playlists, shuffle, track history, and play. Built to demonstrate data structures (linked lists / queues for playlist management) and file system navigation in C++.

---

## ✨ Features

| Command | Description |
|---------|-------------|
| **Select Directory** | Set the current directory to browse audio files from |
| **Change Directory** | Navigate to a different folder |
| **Create Playlist** | Initialize a new named playlist |
| **Insert Audio** | Add an audio file to the current playlist |
| **Delete Audio** | Remove a specific track from the playlist |
| **Play Playlist** | Play all tracks in the playlist sequentially |
| **Shuffle** | Randomize the playback order of the playlist |
| **History** | View previously played tracks |

---

## 🛠️ Tech Stack

- **Language:** C++
- **Interface:** Terminal / Command Line
- **Audio Playback:** Windows `PlaySound()` API (or `mciSendString`)
- **Data Structures:** Linked list / queue for playlist management

---

## 📁 Project Structure

```
mp3-music-player/
│
├── main.cpp              # Entry point + terminal menu
├── player.cpp            # Audio playback logic
├── player.h
├── playlist.cpp          # Playlist — insert, delete, shuffle
├── playlist.h
├── history.cpp           # Playback history tracking
├── history.h
│
└── README.md
```

> **Note:** Update file names to match your actual source files before pushing.

---

## ⚙️ Setup & Run

### Compile

```bash
g++ main.cpp player.cpp playlist.cpp history.cpp -o music_player -lwinmm
```

> `-lwinmm` links the Windows Multimedia library required for audio playback.

### Run

```bash
./music_player
```

---

## 🖥️ Terminal Menu

```
===== MP3 Music Player =====
1. Select Current Directory
2. Change Current Directory
3. Create New Playlist
4. Insert Audio File
5. Delete Audio from Playlist
6. Shuffle Playlist
7. Play Entire Playlist
8. View History
9. Exit
=============================
Enter your choice:
```

---

## 💡 Key Design Decisions

- **Why a linked list for the playlist?** — Insertions and deletions at arbitrary positions are O(1) with a linked list, which is exactly what playlist management needs — add a song anywhere, remove it cleanly.
- **Why track history separately?** — History is a stack/queue structure — last played at the top. Keeping it separate from the playlist means replaying history doesn't corrupt the current playlist order.
- **Why terminal-only?** — Focuses the implementation on data structure logic rather than GUI boilerplate. Everything meaningful happens in the playlist and playback engine.

---

## 🔮 Possible Extensions

- [ ] Cross-platform audio support (replace WinMM with SDL_mixer or miniaudio)
- [ ] Save/load playlists to file
- [ ] Volume control and seek support
- [ ] Display song duration and progress bar in terminal
- [ ] Search tracks by name across directories

---

## 👤 Author

**Abu-Bakar Chaudhary**  
Computer Engineering · NUST · Class of 2027  
[GitHub](https://github.com/abu-bakarchaudhary) · [LinkedIn](https://linkedin.com/in/abu-bakarchaudhary)
