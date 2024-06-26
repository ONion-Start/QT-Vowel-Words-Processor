#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_processButton_clicked() {
    QString input = ui->inputTextEdit->toPlainText();
    QString output = processString(input);
    ui->outputTextEdit->setPlainText(output);
}

void MainWindow::on_generateEnglishButton_clicked() {
    int wordCount = ui->wordCountSpinBox->value();
    int wordLength = ui->wordLengthSpinBox->value();
    QString generatedString = generateString(wordCount, wordLength, false);
    ui->inputTextEdit->setPlainText(generatedString);
}

void MainWindow::on_generateRussianButton_clicked() {
    int wordCount = ui->wordCountSpinBox->value();
    int wordLength = ui->wordLengthSpinBox->value();
    QString generatedString = generateString(wordCount, wordLength, true);
    ui->inputTextEdit->setPlainText(generatedString);
}

void MainWindow::on_helpButton_clicked() {
    QString helpText =
        "Условие задачи:\n\n"
        "Напишите программу, которая принимает строку, состоящую из слов, "
        "разделенных пробелами и знаками препинания (, . ; ! ?). Программа должна "
        "сформировать новую строку, включающую только те слова, которые начинаются "
        "с гласной буквы. Гласные буквы: a, e, i, o, u, y (как в нижнем, так и в верхнем "
        "регистре). В новой строке каждое слово должно начинаться с прописной буквы.\n\n"
        "Требования:\n"
        "1. Исходную строку можно ввести через стандартный ввод.\n"
        "2. Слова в исходной строке могут быть разделены пробелами и знаками препинания (, . ; ! ?).\n"
        "3. В новой строке каждое слово должно начинаться с заглавной буквы.\n"
        "4. Слова в новой строке должны быть разделены пробелами.\n"
        "5. Программа должна быть написана на языке C++ с использованием библиотек Qt.\n";

    QMessageBox::information(this, "Help", helpText);
}

QString MainWindow::processString(const QString &input) {
    QStringList words = input.split(QRegularExpression("[\\s,.!?;]+"), Qt::SkipEmptyParts);
    QStringList result;

    for (const QString &word : words) {
        if (startsWithVowel(word)) {
            result << word.left(1).toUpper() + word.mid(1);
        }
    }

    return result.join(" ");
}

bool MainWindow::startsWithVowel(const QString &word) {
    QString vowels = "aeiouyAEIOUYаеёиоуыэюяАЕЁИОУЫЭЮЯ";
    return vowels.contains(word.left(1));
}

QString MainWindow::generateString(int wordCount, int wordLength, bool isRussian) {
    QString vowels, consonants, punctuation;

    if (isRussian) {
        vowels = "аеёиоуыэюяАЕЁИОУЫЭЮЯ";
        consonants = "бвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩ";
    } else {
        vowels = "aeiouyAEIOUY";
        consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    }

    punctuation = ",.!?;";

    QStringList words;

    for (int i = 0; i < wordCount; ++i) {
        QString word;

        // First letter should be vowel
        word += vowels.at(QRandomGenerator::global()->bounded(vowels.length()));

        for (int j = 1; j < wordLength; ++j) {
            int type = QRandomGenerator::global()->bounded(3);
            if (type == 0) {
                word += vowels.at(QRandomGenerator::global()->bounded(vowels.length()));
            } else if (type == 1) {
                word += consonants.at(QRandomGenerator::global()->bounded(consonants.length()));
            } else {
                word += punctuation.at(QRandomGenerator::global()->bounded(punctuation.length()));
            }
        }

        words << word;
    }

    return words.join(" ");
}

void MainWindow::on_pushButton_clicked()
{

}

