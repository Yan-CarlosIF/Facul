package livro_resolvidas.Q1;

// Defina uma classe chamada PRODUTO com os seguintes atributos: descrição, tipo (que deve existir na classe TIPO),
// preço e imposto e o método calcular o preço final, ou seja, preço mais imposto. Faça um
// programa que carregue os dados de um produto e mostre seu preço final.

public class Product {
    public String description;
    private Type type;
    private double price;
    private double tax;

    public Product(
            String description,
            Type type,
            double price
    ) {
        this.description = description;
        this.type = type;
        this.price = price;
        this.tax = this.price * (type.getPercentage() / 100);
    }

    public Type getType() {
        return type;
    }

    public void setType(Type type) {
        this.type = type;
        setTax(this.price * type.getPercentage() / 100);
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public double getTax() {
        return tax;
    }

    public void setTax(double tax) {
        this.tax = tax;
    }

    public double calculateFinalPrice() {
        return this.price + this.tax;
    }
}
