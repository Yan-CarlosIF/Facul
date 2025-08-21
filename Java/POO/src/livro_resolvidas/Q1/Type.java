package livro_resolvidas.Q1;

//Defina uma classe chamada TIPO com os seguintes atributos: código do tipo e percentual do tipo. Os
//percentuais devem seguir a tabela abaixo.

//     Tipo      | % de imposto
//1. Alimentação | 10
//2. Limpeza     | 20

public class Type {
    private int typeCode;
    private float percentage;

    public Type(int typeCode, float percentage) {
        this.typeCode = typeCode;
        this.percentage = percentage;
    }

    public float getPercentage() {
        return percentage;
    }

    public void setPercentage(float percentage) {
        this.percentage = percentage;
    }

    public int getTypeCode() {
        return typeCode;
    }

    public void setTypeCode(int typeCode) {
        this.typeCode = typeCode;
    }
}