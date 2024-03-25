#ifndef QUANTIDADEDELEGATE_H
#define QUANTIDADEDELEGATE_H

#include <QStyledItemDelegate>
#include <QLineEdit>

class QuantidadDelegate : public QStyledItemDelegate {
public:
    QuantidadDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& /*option*/, const QModelIndex& index) const override {
        // Permitir a edição somente para a coluna de quantidade
        if (index.column() == 2) {
            QLineEdit* editor = new QLineEdit(parent);
            // Aplicar o QIntValidator ao QLineEdit
            editor->setValidator(new QIntValidator(0, 10000, editor)); // limites de 0 a 10000
            return editor;
        }
        return nullptr;
    }
};

#endif // QUANTIDADEDELEGATE_H
