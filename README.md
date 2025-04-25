# 🧠 Qt Exercises - C++ GUI Practice

Practical exercises using **Qt5 and C++**, developed as part of my programming coursework.  
Each project is an individual Qt application focusing on different core topics: GUI components, layouts, signals/slots, file handling, memory, etc.

---

## 📁 Projects

#### 🔢 01 - Post Sorting (`Class arrangement`)
Define a `Post` class with attributes for height and diameter. Stores a custom array of posts and sorts them by height without using `std::vector` or STL algorithms.

---

### 🔤 02 - Idiom Sorter (`Sort idioms no spaces`)
Stores 5 idiomatic expressions in a `std::vector<std::string>`, sorts them alphabetically *ignoring spaces*, and prints the result.

---

### 🧪 03 - Memory Flood (`Memory limit object allocation`)
Defines a custom class and creates instances of it until approximately **200 MB of RAM** is consumed. Shows the total number of objects created.

---

### 🎚️ 04 - Volume Slider (`Volume control window title`)
Synchronizes a `QSlider` and a `QSpinBox`, and updates the window title to reflect the current volume level in real-time.

---

### 🖼️ 05 - Show Image (`Image viewer autoclose`)
Displays a high-resolution image from disk inside a maximized `QLabel`, then auto-closes the application after **3 seconds**. The image does not stretch or deform.

---

### 🔐 06 & 07 - Login + TBD (`QT Login form switch & TBD`)
Implements a login screen with username + password. If correct (`admin:1111`), opens a second form with fields for legajo, name, surname, and a **captcha**.  
Includes:
- Asterisk masking for password
- Pressing Enter triggers login
- Captcha validation
- Input constraints and error feedback

---

## 🛠️ Requirements

- Qt 5.x or 6.x
- C++11 or higher
- Compatible with Qt Creator (qmake project)

---

## 💬 Author

**Tobias Becerra**  
👨‍💻 Contact: TBD

---

## 📄 License

This repo is public and open for educational use. Feel free to fork or adapt.
