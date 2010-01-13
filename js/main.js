$(document).ready(
  function() {
  
//  $("#logo-floater").addClass('cio');
  
  $(".palette-wizard").click(
    function(){
    $(".box_box").slideToggle("slow");
		$(this).toggleClass("active"); return false; 
    return false;
  });
});
