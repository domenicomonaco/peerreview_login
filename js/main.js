$(document).ready(
  function() {

  $(".element-palette-wizard-button").click(
    function(){
    $(".box_box").slideToggle("slow");
		$(this).toggleClass("active"); return false; 
    return false;
  });
  
  
  $(".palette_palette a").hover(
    function(){
		$(this).next("em").animate({opacity: "show", top: "-30",right: "0",}, "slow");
	}, function() {
		$(this).next("em").animate({opacity: "hide", top: "-85", right: "-50"}, "fast");
  });
  


  
});
