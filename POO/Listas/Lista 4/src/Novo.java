public class Novo extends Imovel{
    @Override
    public double getPreco(){
        return super.getPreco()*1.10;
    }
}
