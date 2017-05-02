trait ClonableProduct[+A <: AnyRef] extends Cloneable {
  override def clone(): A = super.clone().asInstanceOf[A]
}

class PrototypeProduct extends ClonableProduct[PrototypeProduct] {
    private var _sold : Boolean = false
    
    def is_sold : Boolean = return _sold
    def sold = {
        _sold = true
    }
}

var product_1 = new PrototypeProduct
println("Create Product 1")
var product_2 = product_1.clone
println("Clone Product 2 from Product 1")
println("Product 2 is sold? " + product_2.is_sold)
println("Product 1 is sold? " + product_1.is_sold)
println("Sold Product 1")
product_1.sold
println("Product 1 is sold? " + product_1.is_sold)
println("Product 2 is sold? " + product_2.is_sold)
var product_3 = product_1.clone
println("Clone Product 3 from Product 1")
println("Product 1 is sold? " + product_1.is_sold)
println("Product 2 is sold? " + product_2.is_sold)
println("Product 3 is sold? " + product_3.is_sold)