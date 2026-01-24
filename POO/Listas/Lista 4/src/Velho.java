class Velho extends Imovel {
    @Override
    public double getPreco() {
        return super.getPreco() * 0.9;
    }
}
